# Site name
As we revisit our Site branding template we currently have an identical copy of our Pattern Lab Site name component using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/block` folder we can modify our template to include the Site name component from Pattern Lab by following these steps:


- Replace the markup in `block--system-branding-block.html.twig` with the following:


    {% include "@components/site-name/site-name.twig"
      with {
        "url": path('<front>'),
        "site_name": site_name
      }
    %}


> **Includes**
> 
> Above we are including the Site name component from Pattern Lab by referencing the namespace and path to the `site-name.twig` file.  We are then using the `with` keyword to pass our Twig variables to the component.  This successfully replaces the markup in Drupal with the markup from Pattern Lab so that future changes to the markup are managed in one location.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Site branding block now matches our Site name component in Pattern Lab.

