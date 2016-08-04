<?php

class GiphyLoaderCache extends GiphyLoaderBase {

  /**
   * {@inheritdoc}
   */
  public function load($id) {
    $giphys = &drupal_static('giphy', array());

    if (isset($giphys[$id])) {
      return $giphys[$id];
    }

    // Attempt to load from cache.
    if ($cache = cache_get("giphy_image:$id", 'cache_giphy')) {
      return $cache->data;
    }

    // Load from API.
    $data = $this->query(array($id));
    $data = reset($data);
    $this->save($id, $data);

    $giphys[$id] = $data;

    return $data;
  }

  /**
   * {@inheritdoc}
   */
  public function loadMultiple($ids) {
    $giphys = &drupal_static('giphy', array());

    $ids = array_combine($ids, $ids);

    // Load from persistent cache where available.
    $cids = array();
    foreach ($ids as $id) {
      if (isset($giphys[$id])) {
        $ids[$id] = $giphys[$id];
      } else {
        $ids[$id] = NULL;
        $cids[$id] = "giphy_image:$id";
      }
    }
    $cache = cache_get_multiple($cids, 'cache_giphy');

    // Load the rest from the API.
    $data = $this->query(array_keys($cids));

    foreach ($ids as $id => $value) {
      if (isset($data[$id])) {
        // Use data queried from the API.
        $ids[$id] = $giphys[$id] = $data[$id];
        $this->save($id, $data[$id]);
      } elseif (isset($cache["giphy_image:$id"])) {
        // Use data loaded from cache.
        $ids[$id] = $giphys[$id] = $cache["giphy_image:$id"]->data;
      }
    }

    return array_filter($ids);
  }

  /**
   * {@inheritdoc}
   */
  public function save($id, $data) {
    cache_set("giphy_image:$id", $data, 'cache_giphy');
  }
}
