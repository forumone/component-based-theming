# Nav Footer
Drupal 8 manages the systems **menu** using the Menu UI and uses multiple templates to output content.  Each Menu has a template associated with it and we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the Footer menu using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `block--system-menu-block.html.twig`.

### Specificity
Before we go haphazardly overriding the `block--system-menu-block.html.twig` we need to keep in mind that all Menus created within Drupal will use this same block regardless if we are outputting a Main menu, a Footer menu, etc.

It would be safer to be more specific in this scenario and create a new Twig template using one of the File Name Suggestions recommended by Drupal.  We will use `block--system-menu-block--footer.html.twig` template.  This will ensure that only our Footer menu is output using this template.

### Nested templates
If we look a little deeper we will notice a second template being used by Drupal to output the menu list.  We can identify the path by expanding the `nav` element.  The menu list is using the `menu.html.twig` template.  However, this Twig template is being used by all Menus in Drupal so again we will want to take advantage of File Name Suggestions and make sure we use `menu--footer.html.twig` instead.  This will ensure that only our Footer menu is output using this menu template.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a block template along with a menu template so its just a matter of how where we want to begin.

## Step Three: Create Menu template
If we navigate to the `/web/themes/pwc/templates/navigation` folder we can begin creating a new Menu template.  Start by following these steps:

- Duplicate `menu.html.twig`
- Rename to `menu--footer.html.twig`
- Replace the markup with the following:

```
  {% import _self as menus %}
  {{ menus.menu_links(items, attributes, 0, menu_name) }}

  {% macro menu_links(items, attributes, menu_level, menu_name) %}
    {% import _self as menus %}
    {% if items %}
      {% spaceless %}
        {% if menu_level == 0 %}
          <ul class="nav nav--menu">
        {% else %}
          <ul class="nav__subnav">
        {% endif %}
        {% for item in items %}
          {%
            set item_classes = [
              'nav__item',
              item.below ? 'has-subnav',
              item.in_active_trail ? 'is-active-trail',
              item.is_collapsed ? 'is-collapsed',
              item.is_expanded ? 'is-expanded',
            ]
          %}
          {%
            set link_attributes = {
              'class': [
                'nav__link',
                item.below ? 'has-subnav',
                item.in_active_trail ? 'is-active-trail',
                item.is_collapsed ? 'is-collapsed',
                item.is_expanded ? 'is-expanded',
              ]
            }
          %}
          <li{{ item.attributes.addClass(item_classes) }}>
            {{ link(item.title, item.url, link_attributes) }}
            {% if item.below %}
              {{ menus.menu_links(item.below, attributes, menu_level + 1) }}
            {% endif %}
          </li>
        {% endfor %}
        </ul>
      {% endspaceless %}
    {% endif %}
  {% endmacro %}
```

- Save the file

## Step Four: Create Block template
If we navigate to the `/web/themes/pwc/templates/block` folder we can begin creating a new Block template.  Start by following these steps:

- Duplicate `block--system-menu-block.html.twig`
- Rename to `block--system-menu-block--footer.html.twig`
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/01-components/nav-footer/` folder and copy the markup.
- Replace the markup in `block--system-menu-block--footer.html.twig` with the following:

```
  <nav class="nav-footer" role="navigation">
    <h2 class="visually-hidden">Footer menu</h2>
    {% spaceless %}
    {% block content %}
    <ul class="nav nav--menu">
      {% for item in items %}
      <li class="nav__item"><a class="nav__link" href="{{ item.url }}">{{ item.text|raw }}</a></li>
      {% endfor %}
    </ul>
    {% endblock %}
    {% endspaceless %}
  </nav>
```

Next we will want to replace the markup between the opening and closing Twig block with `{{ content }}` which will output the `menu--footer.html.twig` template we created earlier.  Our Block template should now look like the following:

```
  <nav class="nav-footer" role="navigation">
    <h2 class="visually-hidden">Footer menu</h2>
    {% spaceless %}
    {% block content %}
      {{ content }}
    {% endblock %}
    {% endspaceless %}
  </nav>
```

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Footer menu now matches our Nav footer component in Pattern Lab.
