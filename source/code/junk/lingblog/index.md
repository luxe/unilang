---
layout: home
---

## {{site.tagline}}
<!-- <div class="main_title_mini_links"> <a href="{{ site.baseurl }}{{ post.url }}"> test </a> </div> -->
{% assign counter = 1 %}
{% for post in site.posts reversed %}
<h3> <i class="little_home">{{ counter }}.</i> <a href="{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a> </h3>
  {% assign counter=counter | plus:1 %}
{% endfor %}