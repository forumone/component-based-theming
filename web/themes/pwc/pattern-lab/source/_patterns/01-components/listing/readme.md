# Listing

## Step One - Building a component
Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.

- Create a new file called `listing.twig`
- Add the following markup:

```
  <article class="listing" role="article">
    <div class="listing__date">July 20, 2017</div>
    <h2 class="listing__heading"><a href="#">Killer whale</a></h2>
  </article>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-listing to view our component.

## Step Two - Using pattern-specific data
Currently our component displays static values.  Lets replace them using pattern-specific data along with Twig variables.

- Create a a new file called `listing.yml`
- Add the following key and value pairs, keeping in mind that YAML requires specific formatting:

```
  listing_url: "#"
  listing_date: "July 20, 2017"
  listing_heading: "Killer whale"
```

- Save the file
- Edit `listing.twig` and replace the static values with Twig variables for each key.

```
  <article class="listing" role="article">
    <div class="listing__date">{{ listing_date }}</div>
    <h2 class="listing__heading"><a href="{{ listing_url }}">{{ listing_heading }}</a></h2>
  </article>
```

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-listing to view our component.

Our Listing component is now complete.
