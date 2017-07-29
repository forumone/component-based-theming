# Nav Footer

## Step One - Building a component
Creating a component is actually quite easy.  All that we need is a twig template with the name of our component and the HTML markup that makes up our component.

- Create a new file called `nav-footer.twig`
- Add the following markup:

```
  <nav class="nav-footer" role="navigation">
    <h2 class="visually-hidden">Footer menu</h2>
    <ul class="nav nav--menu">
      <li class="nav__item"><a class="nav__link" href="#">&copy; 2017 PACIFIC WHALE CONSERVANCY</a></li>
      <li class="nav__item"><a class="nav__link" href="#"> All rights reserved</a></li>
      <li class="nav__item"><a class="nav__link" href="#">Privacy Policy</a></li>
    </ul>
  </nav>
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-nav-footer to view our component.  Keeping in mind that visually we will not see anything since the Footer menu is meant to be against a dark background.

## Step Two - Using pattern-specific data
Currently our component displays static values.  Lets replace them using pattern-specific data along with Twig variables.

- Create a a new file called `nav-footer.yml`
- Add the following key and value pairs, keeping in mind that YAML requires specific formatting:

```
  items:
  -
    url: "#"
    text: "&copy; 2017 PACIFIC WHALE CONSERVANCY"
  -
    url: "#"
    text: "All rights reserved"
  -
    url: "#"
    text: "Privacy Policy"
```

> This time around our YML file introduces another new concept known as a nested array of items. Each item is separated by a dash - representing an object with key and value pairs.  This allows us to mimic the number of menu items we want to display in our Twig file which we will loop thru.

- Save the file
- Edit `nav-footer.twig` and replace the markup with the following.

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

> Lets take a moment to explain some of the different Twig syntax we are introducing which includes Whitespace control, a Twig block, and a Twig control structure.

**Whitespace control**: Twig allows us to control whitespace that markup may introduce by wrapping a section of markup with the `{% spaceless %}` tag.  Anything between the opening and closing `{% spaceless %}` tag is returned unchanged so **(spaces, tabs and newlines)** will not introduce additional whitespace.

**Twig block**: Blocks `{% block %}` are used for inheritance and act as placeholders and replacements at the same time.  This allows us to extend or embed a Twig template and pass content to the template between the opening and closing `{% block %}` tag.  We will explore this further later in the training.

**Twig control structure**: Wrapped around our list item is a `{% for %}` loop which allows us to iterate over each item in a sequence.  The format takes the singular item of a YML file that contains an array of items and allows us to print the key/value for each item using dot syntax notation.

- Save the file
- If Grunt does not recognize the new YML file or changes to it, try stopping and restarting the `grunt` task.
- Refresh browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=components-nav-footer to view our component.

Our Nav Footer component is now complete.
