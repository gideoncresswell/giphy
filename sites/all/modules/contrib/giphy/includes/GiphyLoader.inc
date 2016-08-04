<?php

interface GiphyLoader {

  /**
   * Load data for a Giphy image.
   *
   * @param string $id
   *   The identifier of the Giphy image.
   *
   * @return stdClass
   */
  public function load($id);

  /**
   * Load data for multiple Giphy images.
   *
   * @param array $ids
   *   An array of identifiers of the Giphy images.
   *
   * @return array
   */
  public function loadMultiple($ids);

  /**
   * Query Giphy data from Giphy.
   *
   * @param array $ids
   *   Identifiers for the Giphy images to query.
   *
   * @return array
   *   An array of values, each representing a Giphy image, keyed by id.
   */
  public function query($ids);

  /**
   * Store the Giphy image meta data.
   *
   * @param $id
   *   The Giphy image identifier.
   *
   * @param $data
   *   The Giphy image meta data.
   */
  public function save($id, $data);

}
