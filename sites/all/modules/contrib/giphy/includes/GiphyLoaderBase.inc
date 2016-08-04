<?php

abstract class GiphyLoaderBase implements GiphyLoader {

  /**
   * {@inheritdoc}
   */
  public function query($ids) {
    $return = array();

    // @TODO: break API calls into batches.
    $ids = implode(',', $ids);
    $data = giphy_api_query('gifs', '', array('ids' => $ids));

    foreach ($data->data as $item) {
      $return[$item->id] = $item;
    }

    return $return;
  }

}
