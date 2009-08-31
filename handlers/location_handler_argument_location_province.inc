<?php
// $Id: location_handler_argument_location_province.inc,v 1.2 2009/08/31 22:09:35 bdragon Exp $

/**
 * Argument handler to accept a province code or name.
 */
class location_handler_argument_location_province extends views_handler_argument {
  /**
   * Override the behavior of title(). Get the province name.
   */
  function title() {
    if (isset($this->view->argument['country'])) {
      $country = $this->view->argument['country']->argument;
    }
    else {
      $country = variable_get('site_default_country', 'us');
    }
    return location_province_name($country, $this->argument);
  }

  function summary_name($data) {
    $value = $data->{$this->name_alias};
    if (empty($value)) {
      return t('Unknown');
    }

    if (isset($this->view->argument['country'])) {
      $country = $this->view->argument['country']->argument;
    }
    else {
      $country = variable_get('site_default_country', 'us');
    }

    return location_province_name($country, $value);
  }
}
