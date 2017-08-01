# Site name
Drupal 8 manages its **Site name**, **Site slogan** and **Site logo** using the Site branding block.  
Each block has a Twig template associated with it and we can override these templates by performing a series of steps to locate the path to the current template, identify File Name Suggestions to determine what is being used, what we can use to override the template and then create a copy of the Twig template with the suggested file name that allows us to modify the markup accordingly.

## Step One: Identify template
If we inspect the Site branding block using Google Chrome’s Developer Tools we can identify which Twig template(s) are being used by Drupal to output content.  Start with locating the HTML comment beginning with `FILE NAME SUGGESTIONS` and look for the `X` next to one of the many template names. The `X` identifies which template is being used, which in our case is `block--system-branding-block.html.twig`.

## Step Two: Identify path
In order to identify the path to the template(s) currently being used by Drupal we need to identify the HTML comment starting with `BEGIN OUTPUT`.  In this example though we already have a block template being used by our Site branding block, so our output is `/web/themes/pwc/templates/block`.

## Step Three: Create Block template
If we navigate to the `/web/themes/pwc/templates/block` folder we can begin creating a new Block template.  Start by following these steps:

- Open the `block--system-branding-block.html.twig` template
- Navigate to the Pattern Lab component located in the `/web/themes/pwc/pattern-lab/source/_patterns/01-components/site-name/` folder and copy the markup.
- Replace the markup in `block--system-branding-block.html.twig` with the following:

```
  <a class="site-name" href="{{ url }}" title="{{ 'Home'|t }}" rel="home">
    <h1 class="site-name__text">{{ site_name }}</h1>
  </a>
```

Next we will want to replace the Twig variables that our Pattern Lab markup is currently using with those of the Twig variables being used by Drupal.

- Modify the `block--system-branding-block.html.twig` template so that it looks like the following:

```
  <a class="site-name" href="{{ path('<front>') }}" title="{{ 'Home'|t }}" rel="home">
    <h1 class="site-name__text">{{ site_name }}</h1>
  </a>
```

> We have replaced the `{{ url }}` variable with `{{ path(``'``<front>``'``) }}` which returns the path to the homepage as identified by the config system settings set in the Drupal UI.

- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme system.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Site branding block now matches our Site name component in Pattern Lab.
