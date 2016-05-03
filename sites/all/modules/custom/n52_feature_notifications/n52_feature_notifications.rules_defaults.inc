<?php
/**
 * @file
 * n52_feature_notifications.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function n52_feature_notifications_default_rules_configuration() {
  $items = array();
  $items['rules_comment_for_moderation'] = entity_import('rules_config', '{ "rules_comment_for_moderation" : {
      "LABEL" : "Comment for moderation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "moderation" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [ { "data_is" : { "data" : [ "comment:status" ], "value" : "0" } } ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "9" : "9" } },
            "subject" : "[WIEU-Portal] Comment-Moderation-Request #[comment:cid]",
            "message" : "Dear Moderator,\\r\\na comment is posted for \\r\\n\\r\\n    \\u0022[comment:node:title]\\u0022.\\r\\n    \\r\\nPlease review the information and moderate the comment.\\r\\n\\r\\nAuthor   : \\u0027[comment:author]\\u0027\\r\\nName     : \\u0027[comment:name]\\u0027\\r\\nEmail    : \\u0027[comment:mail]\\u0027\\r\\nHome page: \\u0027[comment:homepage]\\u0027\\r\\nDate     : \\u0027[comment:created]\\u0027\\r\\nIP       : \\u0027[comment:hostname]\\u0027\\r\\nStatus   : \\u0027[comment:status]\\u0027\\r\\nSubject  : \\u0027[comment:subject]\\u0027\\r\\nTitle    : \\u0027[comment:title]\\u0027\\r\\nContent  :\\r\\n----------\\r\\n[comment:body]\\r\\n----------\\r\\n\\r\\nFor publishing, editing, or deleting follow this link\\r\\n\\r\\n    [comment:edit-url]\\r\\n\\r\\nThank you for your time!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact"
          }
        }
      ]
    }
  }');
  $items['rules_new_revision_for_moderation_'] = entity_import('rules_config', '{ "rules_new_revision_for_moderation_" : {
      "LABEL" : "New Revision for moderation -",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "moderation" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "text_matches" : { "text" : [ "revision:log" ], "match" : "ready to review" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "9" : "9" } },
            "subject" : "[[site:name]] Entry revision \\u0022#[revision:vid]\\u0022 ready for review",
            "message" : "Dear Moderator,\\r\\na revision is ready for review.\\r\\n    \\r\\nPlease review the information and publish if compliant with our T\\u0026Cs.\\r\\n-----------------+\\r\\n Author          : \\u0027[revision:author]\\u0027\\r\\n Name            : \\u0027[revision:author:name]\\u0027\\r\\n Created         : \\u0027[revision:created]\\u0027 \\r\\n Lasted update   : \\u0027[revision:changed]\\u0027\\r\\n Entry type      : \\u0027[revision:content-type]\\u0027\\r\\n Title           : \\u0027[revision:title]\\u0027\\r\\n Revision log    : \\u0027[revision:log]\\u0027\\r\\n Revision status : \\u0027[revision:status]\\u0027\\r\\n-----------------+\\r\\n\\r\\nFor publishing follow this link\\r\\n\\r\\n    [revision:edit-url]\\r\\n\\r\\nThank you for your time!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact"
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
            "message" : "Dear [comment:node:author:name],\\r\\nfor your entry\\r\\n\\r\\n    \\u0022[comment:node:title]\\u0022\\r\\n\\r\\na comment is posted and approved by our moderators. It is now published and \\r\\navailable via\\r\\n\\r\\n    [comment:node:url]#comment-[comment:cid]\\r\\n\\r\\nThank you for your patience!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact",
            "language" : [ "comment:node:author:language" ]
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
      "ON" : { "revisioning_pre_publish" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[node:author:name] \\u003C[node:author:mail]\\u003E",
            "subject" : "[WIEU-Portal] Your entry has been published",
            "message" : "Dear [node:author:name],\\r\\nyour entry\\r\\n\\r\\n    \\u0022[revision:title]\\u0022\\r\\n\\r\\nhas been checked and approved by our moderators. It is now published and \\r\\navailable via\\r\\n\\r\\n    [revision:url]\\r\\n\\r\\nThank you for your patience!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_rule_revision_for_moderation'] = entity_import('rules_config', '{ "rules_rule_revision_for_moderation" : {
      "LABEL" : "New Revision for moderation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "moderation" ],
      "REQUIRES" : [ "rules", "revisioning" ],
      "ON" : { "revisioning_post_update" : [] },
      "IF" : [
        { "text_matches" : { "text" : [ "revision:log" ], "match" : "ready to review" } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "9" : "9" } },
            "subject" : "[[site:name]] Entry revision \\u0022#[revision:vid]\\u0022 ready for review",
            "message" : "Dear Moderator,\\r\\na revision is ready for review.\\r\\n    \\r\\nPlease review the information and publish if compliant with our T\\u0026Cs.\\r\\n-----------------+\\r\\n Author          : \\u0027[revision:author]\\u0027\\r\\n Name            : \\u0027[revision:author:name]\\u0027\\r\\n Created         : \\u0027[revision:created]\\u0027 \\r\\n Lasted update   : \\u0027[revision:changed]\\u0027\\r\\n Entry type      : \\u0027[revision:content-type]\\u0027\\r\\n Title           : \\u0027[revision:title]\\u0027\\r\\n Revision log    : \\u0027[revision:log]\\u0027\\r\\n Revision status : \\u0027[revision:status]\\u0027\\r\\n-----------------+\\r\\n\\r\\nFor publishing follow this link\\r\\n\\r\\n    [revision:edit-url]\\r\\n\\r\\nThank you for your time!\\r\\n\\r\\nThe WaterInnEU-Marketplace-Prototype\\r\\n\\r\\n--\\r\\nThis is an automated mail from\\r\\n\\u0022[site:name]\\u0022\\r\\nIf you do not want to receive these mails in future, please get in touch via\\r\\n[site:url]\\/contact"
          }
        }
      ]
    }
  }');
  return $items;
}
