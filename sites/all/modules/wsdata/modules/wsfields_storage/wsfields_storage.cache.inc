<?php

class WsfieldStorageDrupalDatabaseCache extends DrupalDatabaseCache {
  function set($cid, $data, $expire = CACHE_PERMANENT) {
    $cidparts = explode(':', $cid);
    if (
        $cidparts[0] == 'field' and
        wsfields_storage_entity_has_wsfields($cidparts[1]) and
        $expire == CACHE_PERMANENT
      ) {
      $expirecid = 'wsfield_expire:' . $cidparts[1] . ':' . $cidparts[2];
      $expire = cache_get($expirecid);
      if ($expire) {
        $expire = $expire->data;
      } else {
        $expire = time() + variable_get('wsfields_min_expire', 300);
      }
    }
    parent::set($cid, $data, $expire);
  }
}

if (class_exists('MemCacheDrupal')) {
  class WsfieldStorageMemCacheDrupal extends MemCacheDrupal {
    
    function set($cid, $data, $expire = CACHE_PERMANENT, array $headers = NULL) {
      $cidparts = explode(':', $cid);
      if (
          $cidparts[0] == 'field' and
          wsfields_storage_entity_has_wsfields($cidparts[1]) and
          $expire == CACHE_PERMANENT
        ) {
        $expirecid = 'wsfield_expire:' . $cidparts[1] . ':' . $cidparts[2];
        $expire = cache_get($expirecid);
        if ($expire) {
          $expire = $expire->data;
        } else {
          $expire = time() + variable_get('wsfields_min_expire', 300);
        }
      }
      parent::set($cid, $data, $expire, $headers);
    }
  }
}
