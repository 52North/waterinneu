FROM drupal:7.51-apache

MAINTAINER e.h.juerrens@52north.org

# Install PECL extensions
RUN pecl install xdebug
RUN docker-php-ext-enable xdebug