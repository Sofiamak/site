CREATE TABLE  `page` (
   `ID`   BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
   `name` VARCHAR (255)  NOT NULL,
   `content_id`  BIGINT  UNSIGNED  NULL,
   `url`  VARCHAR (255)   NOT NULL,
   `date_created` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
   `date_update`  TIMESTAMP NULL,
    PRIMARY KEY (`ID`),
    INDEX `idx_fk_content`(`content_id` ASC),
    CONSTRAINT `idx_fk_content`
    FOREIGN KEY (`content_id`)
    REFERENCES content(`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION
)ENGINE = InnoDB;

