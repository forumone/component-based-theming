# Nav Main

## Step One - Building a component
Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.

- Create a new file called `nav-main.twig`
- Add the following markup:

```
  <nav class="nav-main" role="navigation">
    <h2 class="visually-hidden">Main menu</h2>
    <input class="nav__trigger" type="checkbox" id="NavButton">
    <label class="nav__label" for="NavButton" onclick>Menu</label>
    <ul class="nav nav--menu">
      <li class="nav__item"><a class="nav__link" href="#">Who we are</a></li>
      <li class="nav__item"><a class="nav__link" href="#">Species</a></li>
      <li class="nav__item"><a class="nav__link" href="#">Our waters</a></li>
      <li class="nav__item"><a class="nav__link nav__link--button" href="#">Donate</a></li>
    </ul>
  </nav>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-nav-main to view our component.  Keeping in mind that visually we will not see anything since the Footer menu is meant to be against a dark background.

## Step Two - Using pattern-specific data
Currently our component displays static values.  Lets replace them using pattern-specific data along with Twig variables.

- Create a a new file called `nav-main.yml`
- Add the following key and value pairs, keeping in mind that YAML requires specific formatting:

```
  items:
  -
    url: "#"
    text: "Who we are"
    modifier: ""
  -
    url: "#"
    text: "species"
    modifier: ""
  -
    url: "#"
    text: "our waters"
    modifier: ""
  -
    url: "#"
    text: "donate"
    modifier: "nav__link--button"
```

- Save the file
- Edit `nav-main.twig` and replace the markup with the following.

```
  <nav class="nav-main" role="navigation">
    <h2 class="visually-hidden">Main menu</h2>
    <input class="nav__trigger" type="checkbox" id="NavButton">
    <label class="nav__label" for="NavButton" onclick>Menu</label>
    {% spaceless %}
    {% block content %}
      <ul class="nav nav--menu">
        {% for item in items %}
        <li class="nav__item"><a class="nav__link {{ item.modifier }}" href="{{ item.url }}">{{ item.text|raw }}</a></li>
        {% endfor %}
      </ul>
    {% endblock %}
    {% endspaceless %}
  </nav>
```

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-nav-main to view our component.

Our Nav Main component is now complete.
