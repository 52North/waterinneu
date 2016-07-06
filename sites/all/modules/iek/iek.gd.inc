<?php

/**
 * @file
 * GD2 toolkit for image manipulation within Drupal.
 */

/**
 * Add an image border by using the GD toolkit.
 *
 * @param object $image
 *   An image object. The $image->resource, $image->info['width'], and
 *   $image->info['height'] values will be modified by this call.
 * @param array $data
 *   An array that contains all the effect parameters.
 *   $data['border_color']: image border color, in Hex format as #cccccc.
 *   $data['border_thick_top']: image top border thick, in pixels.
 *   $data['border_thick_right']: image right border thick, in pixels.
 *   $data['border_thick_bottom']: image bottom border thick, in pixels.
 *   $data['border_thick_left']: image left border thick, in pixels.
 *
 * @return bool
 *   TRUE or FALSE, based on success.
 */
function iek_gd_border(stdClass $image, $data) {
  $border_color = $data['border_color'];
  $border_thick_top = $data['border_thick_top'];
  $border_thick_right = $data['border_thick_right'];
  $border_thick_bottom = $data['border_thick_bottom'];
  $border_thick_left = $data['border_thick_left'];

  $width = $image->info['width'];
  $height = $image->info['height'];

  $border_rgb = iek_image_hex2rgb($border_color);
  $bg_rgb = iek_image_hex2rgb('#ffffff');

  $dst = imagecreatetruecolor($width, $height);
  // Creates background.
  $bg = imagecolorallocate($dst, $bg_rgb['red'], $bg_rgb['green'], $bg_rgb['blue']);
  // Defines border color.
  $border_colors = imagecolorallocate($dst, $border_rgb['red'], $border_rgb['green'], $border_rgb['blue']);

  imagefilledrectangle($dst, 0, 0, $width, $height, $border_colors);
  imagefilledrectangle($dst, $border_thick_left, $border_thick_top, $width - $border_thick_right - 1, $height - $border_thick_bottom - 1, $bg);

  iek_gd_resize($image, array(
    'width' => $width - ($border_thick_left + $border_thick_right),
    'height' => $height - ($border_thick_top + $border_thick_bottom),
    'blank_margin' => FALSE,
    'blank_margin_bg_color' => $border_color,
    'position' => 'middle_center',
  ));

  if (!imagecopy($dst,
    $image->resource,
    $border_thick_left,
    $border_thick_top,
    0,
    0,
    $width - ($border_thick_left + $border_thick_right),
    $height - ($border_thick_top + $border_thick_bottom))) {
    return FALSE;
  }

  // Update image object.
  $image->resource = $dst;
  $image->info['width'] = $width;
  $image->info['height'] = $height;

  return TRUE;
}

/**
 * Add rounded corner by using the GD toolkit.
 *
 * @param object $image
 *   An image object. The $image->resource, $image->info['width'], and
 *   $image->info['height'] values will be modified by this call.
 * @param array $data
 *   An array that contains all the effect parameters.
 *   $data['radius']: radius of the corner, in pixels.
 *
 * @return bool
 *   TRUE or FALSE, based on success.
 */
function iek_gd_corner(stdClass $image, $data) {
  $width = $image->info['width'];
  $height = $image->info['height'];
  $radius = $data['radius'];

  // Finds unique color.
  do {
    $r = rand(0, 255);
    $g = rand(0, 255);
    $b = rand(0, 255);
  } while (imagecolorexact($image->resource, $r, $g, $b) < 0);

  $new_width = $width;
  $new_height = $height;

  $img = imagecreatetruecolor($new_width, $new_height);
  $alphacolor = imagecolorallocatealpha($img, $r, $g, $b, 127);
  imagealphablending($img, FALSE);
  imagesavealpha($img, TRUE);
  imagefilledrectangle($img, 0, 0, $new_width, $new_height, $alphacolor);

  imagefill($img, 0, 0, $alphacolor);
  imagecopyresampled($img, $image->resource, 0, 0, 0, 0, $new_width, $new_height, $width, $height);

  imagearc($img, $radius - 1, $radius - 1, $radius * 2, $radius * 2, 180, 270, $alphacolor);
  imagefilltoborder($img, 0, 0, $alphacolor, $alphacolor);
  imagearc($img, $new_width - $radius, $radius - 1, $radius * 2, $radius * 2, 270, 0, $alphacolor);
  imagefilltoborder($img, $new_width - 1, 0, $alphacolor, $alphacolor);
  imagearc($img, $radius - 1, $new_height - $radius, $radius * 2, $radius * 2, 90, 180, $alphacolor);
  imagefilltoborder($img, 0, $new_height - 1, $alphacolor, $alphacolor);
  imagearc($img, $new_width - $radius, $new_height - $radius, $radius * 2, $radius * 2, 0, 90, $alphacolor);
  imagefilltoborder($img, $new_width - 1, $new_height - 1, $alphacolor, $alphacolor);
  imagealphablending($img, TRUE);
  imagecolortransparent($img, $alphacolor);

  // Resizes image down.
  $dst = imagecreatetruecolor($width, $height);
  imagealphablending($dst, FALSE);
  imagesavealpha($dst, TRUE);
  imagefilledrectangle($dst, 0, 0, $width, $height, $alphacolor);
  imagecopyresampled($dst, $img, 0, 0, 0, 0, $width, $height, $new_width, $new_height);

  // Update image object.
  $image->resource = $dst;
  $image->info['width'] = $width;
  $image->info['height'] = $height;

  return TRUE;
}

/**
 * Add an image padding by using the GD toolkit.
 *
 * @param object $image
 *   An image object. The $image->resource, $image->info['width'], and
 *   $image->info['height'] values will be modified by this call.
 * @param array $data
 *   An array that contains all the effect parameters.
 *   $data['padding_top']: image top padding, in pixels.
 *   $data['padding_right']: image right padding, in pixels.
 *   $data['padding_bottom']: image bottom padding, in pixels.
 *   $data['padding_left']: image left padding, in pixels.
 *   $data['bg_color']: image background color, in Hex format as #cccccc.
 *
 * @return bool
 *   TRUE or FALSE, based on success.
 */
function iek_gd_padding(stdClass $image, $data) {
  $padding_top = $data['padding_top'];
  $padding_right = $data['padding_right'];
  $padding_bottom = $data['padding_bottom'];
  $padding_left = $data['padding_left'];
  $bg_color = $data['bg_color'];
  $width = $image->info['width'];
  $height = $image->info['height'];

  $dst = imagecreatetruecolor($width, $height);
  $bg_rgb = iek_image_hex2rgb($bg_color);
  $bg = imagecolorallocate($dst, $bg_rgb['red'], $bg_rgb['green'], $bg_rgb['blue']);
  imagefilledrectangle($dst, 0, 0, $width, $height, $bg);

  iek_gd_resize($image, array(
    'width' => $width - ($padding_left + $padding_right),
    'height' => $height - ($padding_top + $padding_bottom),
    'blank_margin' => TRUE,
    'blank_margin_bg_color' => $bg_color,
    'position' => 'middle_center',
  ));

  if (!imagecopy($dst,
    $image->resource,
    $padding_left,
    $padding_top,
    0,
    0,
    ($width - ($padding_left + $padding_right)),
    ($height - ($padding_top + $padding_bottom)))) {
    return FALSE;
  }
  imagedestroy($image->resource);

  // Update image object.
  $image->resource = $dst;
  $image->info['width'] = $width;
  $image->info['height'] = $height;
  return TRUE;
}

/**
 * Resize an image by using the GD toolkit.
 *
 * @param object $image
 *   An image object. The $image->resource, $image->info['width'], and
 *   $image->info['height'] values will be modified by this call.
 * @param array $data
 *   An array that contains all the effect parameters.
 *   $data['width']: destination image width, in pixels.
 *   $data['height']: destination image height, in pixels.
 *   $data['blank_margin']: TRUE to show blank margin, FALSE to fulfill bg.
 *   $data['blank_margin_bg_color']: the background color of the blank margin.
 *   $data['position']: the starting position to crop the image.
 *
 * @return bool
 *   TRUE or FALSE, based on success.
 */
function iek_gd_resize(stdClass $image, $data) {
  $debug = FALSE;

  // Resets width and height to zero if they are negative values.
  // Sees the issue: https://drupal.org/node/2141463.
  if ($data['width'] < 0 || $data['height'] < 0) {
    $image->info['width'] = 0;
    $image->info['height'] = 0;
    return TRUE;
  }

  $width = $data['width'];
  $height = $data['height'];
  $blank_margin = $data['blank_margin'];
  $blank_margin_bg_color = !empty($data['blank_margin_bg_color']) ? $data['blank_margin_bg_color'] : '#ffffff';
  $position = $data['position'];

  $dst = imagecreatetruecolor($width, $height);
  $bg_rgb = iek_image_hex2rgb($blank_margin_bg_color);
  $bg = imagecolorallocate($dst, $bg_rgb['red'], $bg_rgb['green'], $bg_rgb['blue']);
  imagefilledrectangle($dst, 0, 0, $width, $height, $bg);

  if ($blank_margin) {
    image_scale($image, $width, $height, TRUE);
  }
  else {
    $src_ratio = round($image->info['width'] / $image->info['height'], 8);
    $dst_ratio = round($width / $height, 8);

    if ($src_ratio >= 1) {
      if ($dst_ratio >= 1) {
        if ($src_ratio > $dst_ratio) {
          if ($debug) {
            dpm('Case 1');
          }
          $scaled_height = $width;
          $scaled_width = $src_ratio * $width;
        }
        else {
          if ($debug) {
            dpm('Case 2');
          }
          $scaled_width = $width;
          $scaled_height = $width / $src_ratio;
        }
      }
      else {
        if ($debug) {
          dpm('Case 3');
        }
        $scaled_height = $height;
        $scaled_width = $src_ratio * $height;
      }
    }
    else {
      if ($dst_ratio >= 1) {
        if ($debug) {
          dpm('Case 11');
        }
        $scaled_width = $width;
        $scaled_height = $width / $src_ratio;
      }
      else {
        if ($src_ratio < $dst_ratio) {
          if ($debug) {
            dpm('Case 12');
          }
          $scaled_width = $height;
          $scaled_height = $height / $src_ratio;
        }
        else {
          if ($debug) {
            dpm('Case 13');
          }
          $scaled_height = $height;
          $scaled_width = $height * $src_ratio;
        }
      }
    }
    $scaled_ratio = round($scaled_width / $scaled_height, 8);

    if ($debug) {
      dpm('$src    : ' . $image->info['width'] . 'x' . $image->info['height']);
      dpm('$dst    : ' . $width . 'x' . $height);
      dpm('$scaled : ' . $scaled_width . 'x' . $scaled_height);

      if ($src_ratio == $scaled_ratio && ($scaled_width - $width) >= 0 && ($scaled_height - $height) >= 0) {
        dpm('Good scaled:');
        dpm('$src_ratio    : ' . $src_ratio);
        dpm('$scaled_ratio : ' . $scaled_ratio);
      }
      else {
        dpm('Bad scaled:');
        dpm('$src_ratio    : ' . $src_ratio);
        dpm('$scaled_ratio : ' . $scaled_ratio);
      }
    }

    image_scale($image, $scaled_width, $scaled_height, TRUE);
  }

  switch ($position) {
    case 'coordinate':
      $src_x = $data['x'];
      $src_y = $data['y'];
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'top_left':
      $src_x = 0;
      $src_y = 0;
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'top_center':
      $src_x = -(($image->info['width'] - $width) / 2);
      $src_y = 0;
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'top_right':
      $src_x = -($image->info['width'] - $width);
      $src_y = 0;
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'middle_left':
      $src_x = 0;
      $src_y = -(($image->info['height'] - $height) / 2);
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'middle_center':
      $src_x = -(($image->info['width'] - $width) / 2);
      $src_y = -(($image->info['height'] - $height) / 2);
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'middle_right':
      $src_x = -($image->info['width'] - $width);
      $src_y = -(($image->info['height'] - $height) / 2);
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'bottom_left':
      $src_x = 0;
      $src_y = -($image->info['height'] - $height);
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'bottom_center':
      $src_x = -(($image->info['width'] - $width) / 2);
      $src_y = -($image->info['height'] - $height);
      $dst_x = 0;
      $dst_y = 0;
      break;

    case 'bottom_right':
      $src_x = -($image->info['width'] - $width);
      $src_y = -($image->info['height'] - $height);
      $dst_x = 0;
      $dst_y = 0;
      break;

    default:
      $src_x = 0;
      $src_y = 0;
      $dst_x = 0;
      $dst_y = 0;
  }

  if (!imagecopy($dst, $image->resource, $src_x, $src_y, $dst_x, $dst_y, $image->info['width'], $image->info['height'])) {
    return FALSE;
  }
  imagedestroy($image->resource);

  // Update image object.
  $image->resource = $dst;
  $image->info['width'] = $width;
  $image->info['height'] = $height;
  return TRUE;
}

/**
 * Add a watermark text on an image by using the GD toolkit.
 *
 * @param object $image
 *   An image object. The $image->resource, $image->info['width'], and
 *   $image->info['height'] values will be modified by this call.
 * @param array $data
 *   An array that contains all the effect parameters.
 *   $data['font']: the font of watermark.
 *   $data['color']: the font color of watermark.
 *   $data['angle']: the rotate angle of watermark.
 *   $data['x']: the x-axis of watermark.
 *   $data['y']: the y-axis of watermark.
 *
 * @return bool
 *   TRUE or FALSE, based on success.
 */
function iek_gd_watermark(stdClass $image, $data) {
  // Replaces text with tokens.
  $text = token_replace($data['text']);
  $angle = 360 - $data['angle'];
  $size = $data['size'];
  $position = $data['position'];
  $padding_top = $data['padding_top'];
  $padding_right = $data['padding_right'];
  $padding_bottom = $data['padding_bottom'];
  $padding_left = $data['padding_left'];
  $width = $image->info['width'];
  $height = $image->info['height'];
  $iek_font = iek_get_watermark_fonts($data['font']);
  $font = drupal_realpath($iek_font['path'] . '/' . $iek_font['file']);

  $dst = imagecreatetruecolor($width, $height);
  $text_rgb = iek_image_hex2rgb($data['color']);
  $text_color = imagecolorallocate($dst, $text_rgb['red'], $text_rgb['green'], $text_rgb['blue']);

  // Wraps the watermark text.
  $bbox = imagettfbbox($size, $angle, $font, $text);
  $bbox_width = abs($bbox[2] - $bbox[0]);
  $bbox_height = abs($bbox[5] - $bbox[3]);
  $bbox_character_width = 0;
  if (strlen($text)) {
    $bbox_character_width = ceil($bbox_width / strlen($text));
  }
  $bbox_character_height = ceil($bbox_height);

  $text_arr = array();
  if ($bbox_character_width) {
    $text_arr = chunk_split($text, ceil(($width - abs(($padding_left + $padding_right) * 2)) / $bbox_character_width), ':::');
    $text_arr = explode(':::', $text_arr);
  }

  switch ($position) {
    case 'top_left':
      $new_y = $bbox_character_height + $padding_top;
      foreach ($text_arr as $text_arr_item) {
        $new_x = $padding_left;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'top_center':
      $new_y = $bbox_character_height + $padding_top;
      foreach ($text_arr as $text_arr_item) {
        $new_x = ($width - $bbox_character_width * strlen($text_arr_item)) / 2;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'top_right':
      $new_y = $bbox_character_height + $padding_top;
      foreach ($text_arr as $text_arr_item) {
        $cur_bbox = imagettfbbox($size, $angle, $font, $text_arr_item);
        $cur_bbox_width = abs($cur_bbox[2] - $cur_bbox[0]);
        $new_x = $width - $cur_bbox_width - $padding_right;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'middle_left':
      $new_y = ($height / 2 - $bbox_character_height * count($text_arr) / 2 + $bbox_character_height);
      foreach ($text_arr as $text_arr_item) {
        $new_x = $padding_left;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'middle_center':
      $new_y = ($height / 2 - $bbox_character_height * count($text_arr) / 2 + $bbox_character_height);
      foreach ($text_arr as $text_arr_item) {
        $new_x = ($width - $bbox_character_width * strlen($text_arr_item)) / 2;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'middle_right':
      $new_y = ($height / 2 - $bbox_character_height * count($text_arr) / 2 + $bbox_character_height);
      foreach ($text_arr as $text_arr_item) {
        $cur_bbox = imagettfbbox($size, $angle, $font, $text_arr_item);
        $cur_bbox_width = abs($cur_bbox[2] - $cur_bbox[0]);
        $new_x = $width - $cur_bbox_width - $padding_left;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'bottom_left':
      $new_y = $height - $bbox_character_height * count($text_arr) - $padding_bottom + $bbox_character_height * 2;
      foreach ($text_arr as $text_arr_item) {
        $new_x = $padding_left;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'bottom_center':
      $new_y = $height - $bbox_character_height * count($text_arr) - $padding_bottom + $bbox_character_height * 2;
      foreach ($text_arr as $text_arr_item) {
        $new_x = ($width - $bbox_character_width * strlen($text_arr_item)) / 2;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    case 'bottom_right':
      $new_y = $height - $bbox_character_height * count($text_arr) - $padding_bottom + $bbox_character_height * 2;
      foreach ($text_arr as $text_arr_item) {
        $cur_bbox = imagettfbbox($size, 0, $font, $text_arr_item);
        $cur_bbox_width = abs($cur_bbox[2] - $cur_bbox[0]);
        $new_x = $width - $cur_bbox_width - $padding_left;
        imagettftext($image->resource, $size, $angle, $new_x, $new_y, $text_color, $font, $text_arr_item);
        $new_y += $bbox_character_height;
      }
      break;

    default:
      $new_x = 0;
      $new_y = 0;
  }
  return TRUE;
}

/**
 * Add a overlay on an image by using the GD toolkit.
 *
 * @param object $image
 *   An image object. The $image->resource, $image->info['width'], and
 *   $image->info['height'] values will be modified by this call.
 * @param array $data
 *   An array that contains all the effect parameters.
 *   $data['overlay_name']: the id name of overlay image.
 *   $data['bg_offset']: the font of watermark.
 *   $data['overlay_offset']: the font color of watermark.
 *
 * @return bool
 *   TRUE or FALSE, based on success.
 */
function iek_gd_overlay(stdClass $image, $data) {
  $iek_overlay = iek_get_overlays($data['overlay_name']);
  $overlay_path = drupal_realpath($iek_overlay['path'] . '/' . $iek_overlay['file']);

  $overlay_info = image_get_info($overlay_path);
  $overlay_tmp = iek_gd_create_image($overlay_path);

  imagecopyresampled($image->resource,
    $overlay_tmp,
    $data['bg_offset'],
    $data['bg_offset'],
    $data['overlay_offset'],
    $data['overlay_offset'],
    $image->info['width'] - ($data['bg_offset'] * 2),
    $image->info['height'] - ($data['bg_offset'] * 2),
    $overlay_info['width'] - ($data['overlay_offset'] * 2),
    $overlay_info['height'] - ($data['overlay_offset'] * 2)
  );
  return TRUE;
}

/**
 * Add a filter on an image by using the GD toolkit.
 *
 * @param object $image
 *   An image object. The $image->resource, $image->info['width'], and
 *   $image->info['height'] values will be modified by this call.
 * @param array $data
 *   An array that contains all the effect parameters.
 *   $data['filter_name']: the filter that will be added to an image.
 *   $data['repeat']: the times to repeat the same filter action.
 *   $data['arg1']:
 *    IMG_FILTER_BRIGHTNESS: Brightness level.
 *    IMG_FILTER_CONTRAST: Contrast level.
 *    IMG_FILTER_COLORIZE: Value of red component.
 *    IMG_FILTER_SMOOTH: Smoothness level.
 *    IMG_FILTER_PIXELATE: Block size in pixels.
 *   $data['arg2']:
 *     IMG_FILTER_COLORIZE: Value of green component.
 *     IMG_FILTER_PIXELATE: Whether to use advanced pixelation effect or not.
 *   $data['arg3']:
 *     IMG_FILTER_COLORIZE: Value of blue component.
 *   $data['arg4']:
 *     IMG_FILTER_COLORIZE: Alpha channel, A value between 0 and 127.
 *     0 indicates completely opaque while 127 indicates completely transparent.
 *
 * @return bool
 *   TRUE or FALSE, based on success.
 */
function iek_gd_filter(stdClass $image, $data) {
  $filter_name = $data['filter_name'];
  $repeat = isset($data['repeat']) ? $data['repeat'] : 1;
  $arg1 = $data['arg1'];
  $arg2 = $data['arg2'];
  $arg3 = $data['arg3'];
  $arg4 = $data['arg4'];

  switch ($filter_name) {
    case IMG_FILTER_BRIGHTNESS:
    case IMG_FILTER_CONTRAST:
    case IMG_FILTER_SMOOTH:
      for ($i = 0; $i < $repeat; $i++) {
        imagefilter($image->resource, $filter_name, $arg1);
      }
      break;

    case IMG_FILTER_PIXELATE:
      for ($i = 0; $i < $repeat; $i++) {
        imagefilter($image->resource, $filter_name, $arg1, $arg2);
      }
      break;

    case IMG_FILTER_COLORIZE:
      for ($i = 0; $i < $repeat; $i++) {
        imagefilter($image->resource, $filter_name, $arg1, $arg2, $arg3, $arg4);
      }
      break;

    default:
      for ($i = 0; $i < $repeat; $i++) {
        imagefilter($image->resource, $filter_name);
      }
      break;
  }

  return TRUE;
}
