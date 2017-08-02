# Listing
As we revisit our Listing template we currently have an identical copy of our Pattern Lab Listing component using Drupal’s Twig variables to display the content.  The challenge with the technique is having to manage to markup in two different places and the issues that this can cause when changes are needed to be made.  We can remedy this now that we have Twig “namespacing” setup to use our templates in Pattern Lab within our Drupal theme.

## Step One: Modify template

If we navigate to the `/web/themes/pwc/templates/content` folder we can modify our template to include the Listing component from Pattern Lab by following these steps:


- Replace the markup in `node--list.html.twig` with the following:


    {% include "@components/listing/listing.twig"
      with {
        "listing_url": url,
        "listing_date": content.field_published|field_value,
        "listing_heading": content.title|field_value
      }
    %}


> **Includes**
> 
> Above we are including the Listing component from Pattern Lab by referencing the namespace and path to the `listing.twig` file.  We are then using the `with` keyword to pass our Twig variables to the component.  This successfully replaces the markup in Drupal with the markup from Pattern Lab so that future changes to the markup are managed in one location.


- Save the Twig template
- Clear Drupal’s cache to ensure any changes are picked up by the theme.  You should only have to do this the first time you introduce a new Twig template to Drupal.

If we refresh the browser we will see that our List display now matches our Listing component in Pattern Lab.

