# Nav footer
As we revisit our Footer menu template we currently have an identical copy of our Pattern Lab Nav footer component using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/block` folder we can modify our template to include the Nav-main component from Pattern Lab by following these steps:


- Replace the markup in `block--system-menu-block--footer.html.twig` with the following:


    {% extends '@components/nav-footer/nav-footer.twig' %}
    
    {% block content %}
      {{ content }}
    {% endblock %}


> **Extends**
> 
> Above we are extending the Nav footer component from Pattern Lab by referencing the namespace and path to the `nav-footer.twig` file.
> 
> When we use a Twig extends it allows us to inherit the markup of our component similar to using an `include` while allowing us to replace content in the component using Twig blocks.  However unlike a Twig include a Twig extends does not allow us to pass variables to template.
> 
> This successfully replaces the markup in Drupal with the markup from Pattern Lab so that future changes to the markup are managed in one location.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Footer menu now matches our Nav footer component in Pattern Lab.

