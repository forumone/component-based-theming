# Teaser

## Step One - Building a component
Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.

- Create a new file called `teaser.twig`
- Add the following markup:

```
  <article class="teaser" role="article">
    <img class="teaser__img" src="/sites/pwc.dd/files/media/image/killer-whales.jpg" alt="Killer whale">
    <div class="teaser__body">
      <div class="teaser__date">July 20, 2017</div>
      <h2 class="teaser__heading"><a href="#">Killer whale</a></h2>
    </div>
  </article>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-teaser to view our component.

## Step Two - Using pattern-specific data
Currently our component displays static values.  Lets replace them using pattern-specific data along with Twig variables.

- Create a a new file called `teaser.yml`
- Add the following key and value pairs, keeping in mind that YAML requires specific formatting:

```
  teaser_image:
    src: "/sites/pwc.dd/files/media/image/killer-whales.jpg"
    alt: "Killer whale"
  teaser_date: "July 20, 2017"
  teaser_url: "#"
  teaser_heading: "Killer whale"
```

- Save the file
- Edit `teaser.twig` and replace the static values with Twig variables for each key.

```
  <article class="teaser" role="article">
    <img class="teaser__img" src="{{ teaser_image.src }}" alt="{{ teaser_image.alt }}">
    <div class="teaser__body">
      <div class="teaser__date">{{ teaser_date }}</div>
      <h2 class="teaser__heading"><a href="{{ teaser_url }}">{{ teaser_heading }}</a></h2>
    </div>
  </article>
```

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-teaser to view our component.

Our Teaser component is now complete.
