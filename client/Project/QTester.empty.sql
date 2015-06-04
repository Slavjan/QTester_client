BEGIN TRANSACTION;
CREATE TABLE "users" (
	`login`	TEXT NOT NULL UNIQUE,
	`name`	TEXT NOT NULL,
	`id_group`	INTEGER NOT NULL
);
CREATE TABLE "user_markers" (
	`id_user`	INTEGER NOT NULL,
	`id_question`	INTEGER NOT NULL,
	`error`	INTEGER NOT NULL DEFAULT 0,
	`dontunderstand`	INTEGER NOT NULL DEFAULT 0,
	PRIMARY KEY(id_user,id_question)
) WITHOUT ROWID;
CREATE TABLE `themes` (
	`title`	TEXT NOT NULL,
	`difficulty`	INTEGER NOT NULL DEFAULT 0,
	`id_lesson`	INTEGER NOT NULL
);
CREATE TABLE `questions` (
	`type`	TEXT NOT NULL DEFAULT 'radio',
	`text`	TEXT NOT NULL,
	`time`	REAL NOT NULL DEFAULT 1.5,
	`case_sensitivity`	INTEGER NOT NULL DEFAULT 0,
	`strip_spaces`	INTEGER NOT NULL DEFAULT 0
);
CREATE TABLE `professions` (
	`code`	TEXT NOT NULL UNIQUE,
	`title`	TEXT
);
CREATE TABLE "lessons" (
	`title`	TEXT NOT NULL,
	`language`	TEXT,
	`course`	INTEGER NOT NULL DEFAULT 1,
	`id_profession`	INTEGER NOT NULL
);
CREATE TABLE `groups` (
	`name`	TEXT NOT NULL UNIQUE,
	`title`	TEXT,
	`course`	INTEGER NOT NULL DEFAULT 1
);
CREATE TABLE `answers` (
	`text`	TEXT,
	`valid`	INTEGER NOT NULL,
	`id_question`	INTEGER NOT NULL
);
;
;
;
COMMIT;
