<?php
/**
 * @file
 * feature_notifications.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function feature_notifications_default_rules_configuration() {
  $items = array();
  $items['rules_comment_for_moderation'] = entity_import('rules_config', '{ "rules_comment_for_moderation" : {
      "LABEL" : "Comment for moderation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "moderation" ],
      "REQUIRES" : [ "rules", "rules_i18n", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [ { "data_is" : { "data" : [ "comment:status" ], "value" : "0" } } ],
      "DO" : [
        { "mail" : {
            "to" : "[site:mail]",
            "subject" : "[WIEU-Portal] Comment-Moderation-Request #[comment:cid]",
            "message" : "Dear Moderator,\\r\\na comment is posted for \\r\\n\\r\\n    \\u0022[comment:node:title]\\u0022.\\r\\n    \\r\\nPlease review the information and moderate the comment.\\r\\n\\r\\nAuthor   : \\u0027[comment:author]\\u0027\\r\\nName     : \\u0027[comment:name]\\u0027\\r\\nEmail    : \\u0027[comment:mail]\\u0027\\r\\nHome page: \\u0027[comment:homepage]\\u0027\\r\\nDate     : \\u0027[comment:created]\\u0027\\r\\nIP       : \\u0027[comment:hostname]\\u0027\\r\\nStatus   : \\u0027[comment:status]\\u0027\\r\\nSubject  : \\u0027[comment:subject]\\u0027\\r\\nTitle    : \\u0027[comment:title]\\u0027\\r\\nContent  :\\r\\n----------\\r\\n[comment:body]\\r\\n----------\\r\\n\\r\\nFor publishing, editing, or deleting follow this link\\r\\n\\r\\n    [comment:edit-url]\\r\\n\\r\\nThank you for your time!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_rule_comment_for_node_published'] = entity_import('rules_config', '{ "rules_rule_comment_for_node_published" : {
      "LABEL" : "Comment for Node is published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "moderation" ],
      "REQUIRES" : [ "rules", "rules_i18n", "comment" ],
      "ON" : { "comment_update" : [], "comment_insert" : [] },
      "IF" : [ { "data_is" : { "data" : [ "comment:status" ], "value" : "1" } } ],
      "DO" : [
        { "mail" : {
            "to" : "[comment:node:author:name] \\u003C[comment:node:author:mail]\\u003E",
            "subject" : "[WIEU-Portal] Comment published for one of your entries",
            "message" : "Dear [node:author:name],\\r\\nyour entry\\r\\n\\r\\n    \\u0022[revision:title]\\u0022\\r\\n\\r\\nhas been checked and approved by our moderators. It is now published and \\r\\navailable via\\r\\n\\r\\n    [revision:url]\\r\\n\\r\\nThank you for your patience!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_rule_node_publish_info'] = entity_import('rules_config', '{ "rules_rule_node_publish_info" : {
      "LABEL" : "Your node is published info",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "moderation" ],
      "REQUIRES" : [ "rules", "rules_i18n", "revisioning" ],
      "ON" : { "revisioning_post_publish" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[node:author:name] \\u003C[node:author:mail]\\u003E",
            "subject" : "[WIEU-Portal]  Your entry has been published",
            "message" : "Dear [node:author:name],\\r\\nyour entry\\r\\n\\r\\n    \\u0022[revision:title]\\u0022\\r\\n\\r\\nhas been checked and approved by our moderators. It is now published and \\r\\navailable via\\r\\n\\r\\n    [revision:url]\\r\\n\\r\\nThank you for your patience!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
