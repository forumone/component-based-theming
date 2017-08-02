# Teaser
As we revisit our Teaser template we currently have an identical copy of our Pattern Lab Teaser component using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/content` folder we can modify our template to include the Teaser component from Pattern Lab by following these steps:


- Replace the markup in `node--teaser.html.twig` with the following:


    {% set img_url = node.field_featured_image.entity.field_image.entity.uri.value|image_style('card') %}
    {% set img_alt = content.field_featured_image|field_target_entity.field_image.alt %}
    
    {% include "@components/teaser/teaser.twig"
      with {
        "teaser_url": url,
        "teaser_image": {
          "src": img_url,
          "alt": img_alt
        },
        "teaser_date": content.field_published|field_value,
        "teaser_heading": content.title|field_value
      }
    %}


> **Includes**
> 
> Above we are including the Teaser component from Pattern Lab by referencing the namespace and path to the `teaser.twig` file.  We are then using the `with` keyword to pass our Twig variables to the component.  This successfully replaces the markup in Drupal with the markup from Pattern Lab so that future changes to the markup are managed in one location.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our Teaser display now matches our Teaser component in Pattern Lab.

