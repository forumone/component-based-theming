# Site name

## Step One - Building a component
Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.

- Create a new file called `site-name.twig`
- Add the following markup:

```
  <a class="site-name" href="#" title="Home" rel="home">
    <h1 class="site-name__text">Pacific Whale Conservancy</h1>
  </a>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-site-name to view our component.

## Step Two - Using pattern-specific data
Currently our component displays static values.  Lets replace them using pattern-specific data along with Twig variables.

- Create a a new file called `site-name.yml`
- Add the following key and value pairs, keeping in mind that YAML requires specific formatting:

```
  url: "#"
  site_name: "Pacific Whale Conservancy"
```

- Save the file
- Edit `site-name.twig` and replace the static values with Twig variables for each key.

```
  <a class="site-name" href="{{ url }}" title="{{ 'Home'|t }}" rel="home">
    <h1 class="site-name__text">{{ site_name }}</h1>
  </a>
```

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-site-name to view our component.

Our Site name component is now complete.
