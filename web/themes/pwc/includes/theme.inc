<?php

/**
 * Implements theme_suggestions_taxonomy_term_alter()
 *
 * @param $suggestions
 * @param $variables
 */
function pwc_theme_suggestions_taxonomy_term_alter(array &$suggestions, array $variables) {
  $suggestions[] = 'taxonomy_term__' . $variables['elements']['#view_mode'];
}
