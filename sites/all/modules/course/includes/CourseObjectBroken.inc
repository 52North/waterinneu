<?php

class CourseObjectBroken extends CourseObject {

  function take() {
    return t('This course object is misconfigured. Please contact the administrator.');
  }

}
