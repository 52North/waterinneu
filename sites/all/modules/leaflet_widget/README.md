# Leaflet Widget

A [Geofield] widget that provides a [Leaflet] map widget with the
[Leaflet.widget] plugin for adding features. [Leaflet.widget] uses the
[Leaflet.draw] geometry creation tools.

## Features:

- Create & manage simple geometries: Point, LineString, Polygon.
- Maintains complex geometries: MultiPoint, MultiLineString, MultiPolygon and
  GeometryCollection. (These can't be created yet but it won't mess with your
  existing data.)
- Delete geometries.
- Supports single or multi-value Geofields (cardinality).
- Use base layers defined by [Leaflet module].

## Installation tips:

- Download [Leaflet.widget] and place it in your libraries directory (see 
  [Libraries API]). E.g: sites/all/libraries
- Download [Leaflet.draw] and place it in your libraries directory (see 
  [Libraries API]). E.g: sites/all/libraries
- Requires [Leaflet] to be available. By default the version bundled with
  [Leaflet.widget] will be used. However if you have [Leaflet module] installed
  and [Leaflet] located at <path/to/libraries>/leaflet, that version will be
  used.
- This module requires the latest dev release of [GeoPHP] as there are issues 
  with parsing GeoJSON in the latest stable release.

## Requires:

- [Libraries API] (2.x)
- [Geofield] (1.x & 2.x) - Choose the same version of this module.

[Leaflet]: http://leaflet.cloudmade.com
[GeoPHP]: http://drupal.org/project/geophp
[Leaflet module]: http://drupal.org/project/leaflet
[Geofield]: http://drupal.org/project/geofield
[Leaflet.draw]: https://github.com/Leaflet/Leaflet.draw
[Leaflet.widget]: https://tnightingale.github.com/Leaflet.widget
[Libraries API]: http://drupal.org/project/libraries
