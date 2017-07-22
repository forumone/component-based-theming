<?php
/**
 * @file
 * HTML template functions.
 */

/**
 * Implements hook_preprocess_html().
 */
function pwc_preprocess_html(&$vars, $hook) {
  // Add x-ua-compatible meta tag.
  $vars['page']['#attached']['html_head'][] = [
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'http-equiv' => 'x-ua-compatible',
        'content' => 'ie=edge',
      ),
    ),
    'x_ua_compatible'
  ];
}

/**
 * Implements hook_preprocess_maintenance_page().
 */
function pwc_preprocess_maintenance_page(&$vars, $hook) {
  // While markup for normal pages is split into html.html.twig and
  // page.html.twig, the markup for the maintenance page is all in the single
  // maintenance-page.html.twig template. So, to have what’s done in
  // gesso_preprocess_html() and gesso_preprocess_page() also happen
  // on the maintenance page, it has to be called here.
  pwc_preprocess_html($vars, $hook);
  pwc_preprocess_page($vars, $hook);
}

/**
 * Implements hook_preprocess_page().
 */
function pwc_preprocess_page(&$vars, $hook) {}

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function pwc_preprocess_menu_local_tasks(&$variables) {
  foreach (array('primary', 'secondary') as $type) {
    $tabs = array();

    // Sort the tabs by #weight.
    uasort($variables[$type], array('Drupal\Component\Utility\SortArray', 'sortByWeightProperty'));

    foreach (array_keys($variables[$type]) as $key) {
      // Add the tab to a new array.
      $tabs[$key] = array(
        'active' => $variables[$type][$key]['#active'],
        'url' => $variables[$type][$key]['#link']['url']->toString(),
        'text' => \Drupal\Component\Utility\Html::escape($variables[$type][$key]['#link']['title'])
      );

      // Check if the tab should be shown by rendering the original.
      $link = drupal_render($variables[$type][$key]);
      if (!$link) {
        unset($tabs[$key]);
      }
    }

    // Overwrite the original tabs data.
    $variables[$type] = $tabs;
  }
}
