# Homepage

## Step One - Building a template
Creating a template is actually quite easy.  All that we need is a twig template with the name of our template and the HTML markup that makes up our component.

- Create a new file called `homepage.twig`
- Add the following markup:

```
  {% include "layouts-header" %}
  {% include "layouts-main" %}
  {% include "layouts-footer" %}
```

- Save the file
- Refresh your browser and navigate to http://pwc.dd:8083/themes/pwc/pattern-lab/public/?p=templates-homepage to view our template.

Our Homepage template is now complete.

At this point we should have a thorough understanding of how Twig includes play a vital part in piecing together components, layouts and templates to quickly build out a site within Pattern Lab.
