#include <mysqlx/xapi.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void insert_quentitys(mysqlx_session_t* sess){

	string str = "";
	char err_msg[256] = {};
	int err_code = 0;
	mysqlx_result_t* res;
	char* query = NULL;

	//creration of an sql connection aka session to the mysql server
	sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "root", "", err_msg, &err_code);
	if (NULL == sess) {
		cerr << err_msg << endl;
		exit(err_code);
	}
	str = "DROP SCHEMA IF  EXISTS `my_db`;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "CREATE SCHEMA IF NOT EXISTS `my_db`;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "CREATE TABLE IF NOT EXISTS `my_db`.`album` (  `id` INT(11) NOT NULL AUTO_INCREMENT,  `album_name` VARCHAR(45) NULL DEFAULT NULL,  `start_date` DATE NULL DEFAULT NULL,  `end_date` DATE NULL DEFAULT NULL,  `num_of_songs` INT(11) NULL DEFAULT NULL,  PRIMARY KEY (`id`)) ENGINE = InnoDB AUTO_INCREMENT = 11;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "CREATE TABLE IF NOT EXISTS `my_db`.`album_producer` ( `album_id` INT(11) NULL DEFAULT NULL, `producer_id` INT(11) NULL DEFAULT NULL,   INDEX `FK` (`album_id` ASC, `producer_id` ASC) VISIBLE) ENGINE = InnoDB;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "CREATE TABLE IF NOT EXISTS `my_db`.`instrument_type` (  `id` INT(11) NOT NULL AUTO_INCREMENT, `description` VARCHAR(45) NULL DEFAULT NULL, PRIMARY KEY (`id`)) ENGINE = InnoDB AUTO_INCREMENT = 11;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();
	str = "CREATE TABLE IF NOT EXISTS `my_db`.`instruments_stock` ( `id` INT(11) NOT NULL AUTO_INCREMENT, `instrumen_type_id` INT(11) NULL DEFAULT NULL,  `manufacturer_id` INT(11) NULL DEFAULT NULL, PRIMARY KEY (`id`), INDEX `FK` (`instrumen_type_id` ASC, `manufacturer_id` ASC) VISIBLE) ENGINE = InnoDB AUTO_INCREMENT = 17;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "CREATE TABLE IF NOT EXISTS `my_db`.`manufacturers` (`id` INT(11) NOT NULL AUTO_INCREMENT,  `manufacturer_name` VARCHAR(45) NULL DEFAULT NULL, PRIMARY KEY (`id`), INDEX `FK` (`manufacturer_name` ASC) VISIBLE) ENGINE = InnoDB AUTO_INCREMENT = 11;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = " CREATE TABLE IF NOT EXISTS `my_db`.`musical_track` (`id` INT(11) NOT NULL AUTO_INCREMENT, `track_name` VARCHAR(45) NULL DEFAULT NULL, `author_id` INT(11) NULL DEFAULT NULL, `composer_id` INT(11) NULL DEFAULT NULL,  `track_type_id` INT(11) NULL DEFAULT NULL,  `duration` INT(45) NULL DEFAULT NULL,  `genre` VARCHAR(45) NULL DEFAULT NULL,  `recording_date` DATE NULL DEFAULT NULL,  `technician_id` INT(11) NULL DEFAULT NULL, PRIMARY KEY (`id`), INDEX `FK` (`author_id` ASC, `composer_id` ASC, `track_type_id` ASC, `technician_id` ASC) VISIBLE) ENGINE = InnoDB AUTO_INCREMENT = 11;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();
	str = " CREATE TABLE IF NOT EXISTS `my_db`.`musical_track` (`id` INT(11) NOT NULL AUTO_INCREMENT, `track_name` VARCHAR(45) NULL DEFAULT NULL, `author_id` INT(11) NULL DEFAULT NULL, `composer_id` INT(11) NULL DEFAULT NULL,  `track_type_id` INT(11) NULL DEFAULT NULL,  `duration` INT(45) NULL DEFAULT NULL,  `genre` VARCHAR(45) NULL DEFAULT NULL,  `recording_date` DATE NULL DEFAULT NULL,  `technician_id` INT(11) NULL DEFAULT NULL, PRIMARY KEY (`id`), INDEX `FK` (`author_id` ASC, `composer_id` ASC, `track_type_id` ASC, `technician_id` ASC) VISIBLE) ENGINE = InnoDB AUTO_INCREMENT = 11;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = " CREATE TABLE IF NOT EXISTS `my_db`.`musician_instrument` ( `musician_id` INT(11) NULL DEFAULT NULL, `instrument_id` INT(11) NULL DEFAULT NULL,   INDEX `FK` (`musician_id` ASC, `instrument_id` ASC) VISIBLE) ENGINE = InnoDB;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "CREATE TABLE IF NOT EXISTS `my_db`.`person` ( `id` INT(11) NOT NULL AUTO_INCREMENT,  `name` VARCHAR(45) NULL DEFAULT NULL,  `address` VARCHAR(45) NULL DEFAULT NULL, `phone` VARCHAR(45) NULL DEFAULT NULL, PRIMARY KEY (`id`)) ENGINE = InnoDB AUTO_INCREMENT = 11;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = " CREATE TABLE IF NOT EXISTS `my_db`.`role` ( `id` INT(11) NOT NULL AUTO_INCREMENT,  `job_description` VARCHAR(45) NULL DEFAULT NULL, PRIMARY KEY (`id`), INDEX `Key` (`job_description` ASC) VISIBLE) ENGINE = InnoDB AUTO_INCREMENT = 12;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "CREATE TABLE IF NOT EXISTS `my_db`.`roles_of_person` ( `person_id` INT(11) NULL DEFAULT NULL, `role_id` INT(11) NULL DEFAULT NULL,   INDEX `FK` (`person_id` ASC, `role_id` ASC) VISIBLE) ENGINE = InnoDB; ";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = " CREATE TABLE IF NOT EXISTS `my_db`.`track_instruments` ( `track_id` INT(11) NULL DEFAULT NULL, `instrument_id` INT(11) NULL DEFAULT NULL,   INDEX `FK` (`track_id` ASC, `instrument_id` ASC) VISIBLE) ENGINE = InnoDB;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();
	str = " CREATE TABLE IF NOT EXISTS `my_db`.`track_musician` ( `track_id` INT(11) NULL DEFAULT NULL, `musician_id` INT(11) NULL DEFAULT NULL,   INDEX `FK` (`track_id` ASC, `musician_id` ASC) VISIBLE) ENGINE = InnoDB;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = " CREATE TABLE IF NOT EXISTS `my_db`.`track_type` (  `id` INT(11) NOT NULL AUTO_INCREMENT, `type` VARCHAR(45) NULL DEFAULT NULL, PRIMARY KEY (`id`)) ENGINE = InnoDB AUTO_INCREMENT = 4;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = " CREATE TABLE IF NOT EXISTS `my_db`.`tracks_album` ( `track_id` INT(11) NULL DEFAULT NULL, `album_id` INT(11) NULL DEFAULT NULL,   INDEX `FK` (`track_id` ASC, `album_id` ASC) VISIBLE) ENGINE = InnoDB;";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = " INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES (1,'Margalit_Zanani_hameitav', '2015-01-01', '2017-01-01', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES (2,'Yehuda_Poliker_efer_ve'avak', '1988 - 01 - 01', '1988 - 12 - 31', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES (3,'kaveret_sipurei_fogi', '1973-01-01', '1973-12-31', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str ="INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES(4,'Hava_Alberstein', '1975-01-01', '1975-12-31', '2')";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES(5,'Shlomo_Arzi_Drachim', '1979-01-01', '1979-12-31', '7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES(6,'Meir_Banai_geshem', '1987-01-01', '1987-12-31', '1'); ";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES(7,'Benzin_24_shaot', '1982-01-01', '1982-12-31', '4'); ";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES(8,'Eyal_Golan_biladaich', '1997-01-01', '1977-12-31', '9');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES(9,'Tango_sidur_Kavua', '1984-01-01', '1984-12-31', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album` (`id`,`album_name`, `start_date`, `end_date`, `num_of_songs`) VALUES(10,'Zila_Dagan_Zila_Dagan', '1970-01-01', '1970-12-31', '6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();
	

	str = "INSERT INTO `my_db`.`album_producer` (`id`,`album_id`, `producer_id`) VALUES(1, 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(2, 3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(2, 2);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(3, 3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(4, 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(5, 2);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(2, 3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(6, 3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(7, 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(2, 3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(7, 2);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(8, 3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(9, 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`album_producer` (`album_id`, `producer_id`) VALUES(10, 2);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(1, 'Electric Guitar');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(1, 'Electric Guitar');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(2, 'Classic Guitar');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(2, 'Classic Guitar');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(3, 'Acoustic Guitar');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(4, 'Flute');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(5, 'drum');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(6, 'saxophone');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(7, 'bass guitar');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(8, 'piano');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(9, 'Violin');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instrument_type` (`id`, `description`) VALUES(10, 'hood');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(1, 1, 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(2, 3, 4)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(3, 2, 3)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(4, 4, 2)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(5, 5, 5)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(7, 7, 8)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(8, 6, 7)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(9, 7, 9)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(10, 8, 9)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(11, 9, 8)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(12, 5, 1)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(13, 9, 10)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`instruments_stock` (`id`, `instrumen_type_id`, `manufacturer_id`) VALUES(14, 7, 10)";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(1, 'manufacturer1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(2, 'manufacturer2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(3, 'manufacturer3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(4, 'manufacturer4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(5, 'manufacturer5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(6, 'manufacturer6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(7, 'manufacturer7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(8, 'manufacturer8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(9, 'manufacturer9');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`manufacturers` (`id`, `manufacturer_name`) VALUES(10, 'manufacturer10');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(1, 'basbusa',1,2,1,120,'classic','1978-12-05',11);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(2, 'ahim badam',2,2,1,130,'hiphop','1978-11-05',1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(3,'nahon leHayom',3,2,2,170,'classic','1978-01-05',11);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(4, 'haver v-heah',4,2,2,170,'classic','1978-12-05',1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(5, 'marlen', 1, 2, 3, 200, 'rock', '1987-01-05', 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(6,'Badad',2,2,3,220,'classic','1975-09-02',11);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(7,'shar MeHalev',3,2,1,123,'hiphop','1988-08-30',1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(8,'disco menayek',4,2,1,90,'rock','1985-03-15',11);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(8,'disco menayek',4,2,1,90,'rock','1985-03-15',11);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(9, 'Ad matai', 3, 2, 2, 147, 'metal','1992-06-05', 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(9, 'Ad matai', 3, 2, 2, 147, 'metal','1992-06-05', 1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musical_track` (`id`,`track_name`, `author_id`, `composer_id`,`track_type_id`,`duration`,`genre`,`recording_date`,`technician_id`) VALUES(10,'kama od',4,2,3,300,'rock','1995-11-05',1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(1,1);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(1,2);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(2,3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(2,4);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(3,5);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(3,6);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(3,7);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(4,8);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(4,3);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(5,9);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`musician_instrument` (`musician_id`, `instrument_id`) VALUES(6,10);";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();



	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES(1,'Nissim','gaza','052-9511114');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	//if (res == NULL)
	//{
	//	cout << "error";
	//}
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES(2,'Yossi','Netanya','052-9511114');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES(3,'David','Tel-Aviv','052-9876543');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES(4,'Yaki','Zoran','052-9497893');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES(5,'Daniel','Jerusalem','053-9874125');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES('6', 'Shimon', 'Ramat-Ha'sharon', '052-8796542');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES('7', 'linoy', 'Tel-Aviv', '052-1234789');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES('8', 'Joni', 'ramla', '053-2314586');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES('9', 'mohamad', 'lod', '054-5214533');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES('10', 'Fadi', 'Ara', '052-8749234');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`person` (`id`, `name`, `address`, `phone`) VALUES('11', 'michael', 'hodash', '052-5436910');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('1', 'technician');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('2', 'producer');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('3', 'composer');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('4', 'guitarist');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('5', 'bassist');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('6', 'pianist');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('7', 'First voice singer');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('8', 'Second voice singer');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('9', 'singer');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('10', 'author');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`role` (`id`, `job_description`) VALUES('11', 'impresario');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('1', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('1', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('1', '11');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('2', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('2', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('2', '11');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('3', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('3', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('3', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('3', '11');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('4', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('4', '11');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('5', '7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('6', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('7', '9');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('8', '9');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('8', '10');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`roles_of_person` (`person_id`, `role_id`) VALUES('9', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('1', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('2', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('3', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('3', '6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('3', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('4', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('4', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('4', '7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('5', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('5', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('6', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('7', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('8', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('9', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_instruments` (`track_id`, `instrument_id`) VALUES('10', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('1', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('1', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('2', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('2', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('2', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('3', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('3', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('3', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('3', '6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('3', '7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('4', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('4', '6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('4', '7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('4', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('5', '6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('6', '7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('7', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('9', '7');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_musician` (`track_id`, `musician_id`) VALUES('10', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_type` (`id`, `type`) VALUES('1', 'vocal');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_type` (`id`, `type`) VALUES('2', 'instrumental');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`track_type` (`id`, `type`) VALUES('3', 'song');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('1', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('1', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('1', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('1', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('1', '6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('2', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('2', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('2', '3');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('2', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('2', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('2', '6');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('3', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('4', '5');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('5', '2');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('6', '4');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('6', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('7', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('8', '9');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('9', '8');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('9', '9');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('9', '10');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();

	str = "INSERT INTO `my_db`.`tracks_album` (`track_id`, `album_id`) VALUES('10', '1');";
	res = mysqlx_sql(sess, str.c_str(), MYSQLX_NULL_TERMINATED);
	str.clear();


	/*str = "";
	query = new char[str.length() + 1];
	strcpy_s(query, str.length() + 1, str.c_str());
	res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);
	delete[] query;
	str.clear();

	str = "";
	query = new char[str.length() + 1];
	strcpy_s(query, str.length() + 1, str.c_str());
	res = mysqlx_sql(sess, query, MYSQLX_NULL_TERMINATED);
	delete[] query;
	str.clear();*/
}

void queryOne(string first, string second, mysqlx_session_t* sess) {

	//string query = "SELECT count(*) FROM my_db.album where start_date >= '1988-01-01' and end_date <= '2017-01-01';";
	string query = "SELECT count(*) FROM album WHERE start_date >='"+first+"'AND end_date <='"+second+"';";
	/*
	"SELECT * FROM album WHERE start_date >= ? AND end_date <= ?;*/

	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	int64_t x;
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				//size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "the number of between dates:" << x << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void queryTwo(string first, string second, mysqlx_session_t* sess) {
	string fname;
	cout << "please insert musician first name:" << endl;
	cin >> fname;
	cout << endl;
	string query = "SELECT count(*) FROM track_musician LEFT JOIN musical_track ON musical_track.id = track_musician.track_id left join person on track_musician.musician_id = person.id WHERE recording_date between '" + first + "' AND '" + second + "' and person.name = '" + fname + "';";
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	int64_t x;
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				//size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "the number of songs that " << fname << " " << " praticipate between dates: " << x << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void queryThird(string first, string second, mysqlx_session_t* sess) {
	string fname;
	cout << "please insert musician first name:" << endl;
	cin >> fname;
	cout << endl;


	/*string query = "select  count(distinct(album_has_song.album_album_id)) "\
		"from song_has_musician join musician "\
		"on musician.musician_id = song_has_musician.musician_musician_id "
		"and musician.mus_f_name = '" + fname + "' and musician.mus_l_name = '" + last + "' "\
		"and song_has_musician.song_rec_date between '" + first + "' and '" + second + "' "\
		"join album_has_song on song_has_musician.song_song_name = album_has_song.song_song_name;";*/
	string query = "SELECT DISTINCT count(album.id), person.name FROM track_musician LEFT JOIN musical_track ON track_musician.track_id=musical_track.id LEFT JOIN person ON track_musician.musician_id=person.id LEFT JOIN tracks_album ON musical_track.id= tracks_album.track_id LEFT JOIN album ON album.id=tracks_album.album_id WHERE start_date >= '" + first + "'	AND end_date <= '" + second + "' AND person.name = '" + fname + "';";

	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	int64_t x;
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				//size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "the number of albums that " << fname << " "  << " praticipate between dates: " << x << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void queryFour(mysqlx_session_t* sess) {
	/*string query = "select inst_type "\
		"from musician_has_instrument join musician "\
		"on musician.musician_id = musician_has_instrument.musician_musician_id "\
		"join instrument on instrument_instrument_id = instrument.instrument_id "\
		"group by inst_type "\
		"order by count(inst_type) desc limit 1;";*/
	string query = "SELECT  instrument_type.description , instrument_id , count(instrument_id) AS ct FROM track_instruments LEFT JOIN instruments_stock ON track_instruments.instrument_id = instruments_stock.id LEFT JOIN instrument_type ON instruments_stock.instrumen_type_id = instrument_type.id GROUP BY instrument_id ORDER BY ct DESC LIMIT 1;";

	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "the must common instrument is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void queryFifth(mysqlx_session_t* sess) {
	string input;
	cout << "please insert album name:\n";
	cin >> input;
	string query = "SELECT distinct( instrument_type.description) FROM track_instruments LEFT JOIN tracks_album ON track_instruments.track_id=tracks_album.track_id LEFT JOIN album ON album.id = tracks_album.album_id LEFT JOIN instruments_stock AS ins_stock ON ins_stock.id=track_instruments.instrument_id LEFT JOIN instrument_type ON ins_stock.instrumen_type_id = instrument_type.id LEFT JOIN manufacturers AS manf ON ins_stock.manufacturer_id = manf.id WHERE album.album_name = '" + input + "';";
	int i = 1;
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());
	cout << input;
	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			cout << "the list of instruments  in this album:" << endl;
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << i << ") " << buff << endl;
				row = mysqlx_row_fetch_one(res);
				++i;
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void querySixth(string first, string second, mysqlx_session_t* sess) {
	
	string query = "SELECT person.name FROM album_producer LEFT JOIN album ON album_producer.album_id=album.id LEFT JOIN person ON person.id= album_producer.producer_id WHERE (start_date >='" + first + "' AND end_date <= '" + second + "') GROUP BY album_producer.producer_id LIMIT 1;";
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "the busyiest producer is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void querySeventh(mysqlx_session_t* sess) {
	
	string query = "SELECT manufacturer_name FROM(SELECT instruments_stock.manufacturer_id, count(instruments_stock.manufacturer_id) as ct FROM track_instruments LEFT JOIN instruments_stock ON track_instruments.instrument_id = instruments_stock.id GROUP BY instruments_stock.manufacturer_id ORDER BY ct DESC LIMIT 1) AS manf LEFT JOIN manufacturers on manf.manufacturer_id = manufacturers.id;";
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "the must common manufacturer is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}

	delete[] query1;
}

void queryEigth(mysqlx_session_t* sess) {

	string query = "SELECT count( DISTINCT (track_musician.musician_id)) AS ct FROM track_musician;";
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	int64_t x;
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				//size = sizeof(buff);
				mysqlx_get_sint(row, 0, &x);
				cout << "the number of musician recored in the studio:" << x << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void queryNinth(mysqlx_session_t* sess) {
	string query = "SELECT musician.musician_name,  COUNT(*) AS count FROM song_with INNER JOIN musician ON song_with.musician_id = musician.musician_id GROUP BY musician.musician_name ORDER BY count DESC LIMIT 1;";
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "The musician who collaborated with most other musicians is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void queryTenth(mysqlx_session_t* sess) {
	string query = "SELECT genre FROM musical_track GROUP BY musical_track.genre LIMIT 1;";
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "The most common genre is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}

	delete[] query1;
}

void queryEleventh(string first, string second, mysqlx_session_t* sess) {
	string query = "SELECT person.name FROM musical_track LEFT JOIN `person` ON musical_track.technician_id = person.Id WHERE (recording_date >= '" + first + "' AND recording_date <= '" + second + "' ) GROUP BY musical_track.technician_id LIMIT 1;";
	cout << endl;
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "The most busy technician is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}

	delete[] query1;
}

void queryTwelve(mysqlx_session_t* sess) {
	string query = "SELECT album_name FROM album WHERE end_date =  ( SELECT MIN(end_date) FROM album );";

	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "The first album was recorded in the studio is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}

	delete[] query1;
}

void queryThirteen(mysqlx_session_t* sess) {
	int i = 1;
	string query = "SELECT track_name FROM tracks_album RIGHT JOIN musical_track ON tracks_album.track_id = musical_track.id  GROUP BY tracks_album.track_id  HAVING count(track_id) >1;";
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			cout << "the songs that appear in two or more albums are:" << endl;
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << i <<") "<< buff << endl;
				row = mysqlx_row_fetch_one(res);
				++i;
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}

	delete[] query1;
}

void queryFourteenth( mysqlx_session_t* sess) {
	string query = "SELECT distinct(person.name) FROM (SELECT tb.album_id,tb.technician_id,count(tb.technician_id) AS ct FROM (SELECT track.id , track.track_name , tracks_album.album_id , track.technician_id ,count(technician_id) FROM musical_track AS track LEFT JOIN tracks_album ON track.id = tracks_album.track_id GROUP BY track.technician_id ,tracks_album.album_id ORDER BY tracks_album.album_id ASC) AS tb GROUP BY tb.album_id) AS tb1 LEFT JOIN person ON person.id=tb1.technician_id WHERE tb1.ct =1;";
	int i = 1;
	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			cout << "the technicians that took part in recording full albums are:" << endl;
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << i << ") " << buff << endl;
				row = mysqlx_row_fetch_one(res);
				++i;
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}
	delete[] query1;
}

void queryFifteen(mysqlx_session_t* sess) {
	string query = "SELECT tb.name FROM (SELECT  musician_id, genre ,person.name,count(*) AS ct FROM track_musician LEFT JOIN musical_track ON track_musician.track_id =musical_track.id LEFT JOIN person ON person.id = musician_id GROUP BY musician_id, genre) AS tb GROUP BY tb.name ORDER BY count(tb.musician_id) DESC LIMIT 1;";

	char* query1 = new char[query.length() + 1];
	strcpy_s(query1, query.length() + 1, query.c_str());

	//	cout << query1;
	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);
	if (NULL != res) {
		char buff[256]; size_t size = 0;

		do {
			mysqlx_row_t* row = mysqlx_row_fetch_one(res);
			while (NULL != row) {
				size = sizeof(buff);
				mysqlx_get_bytes(row, 0, 0, buff, &size);
				cout << "The must diversified musician in the studio is: " << buff << endl << endl;
				row = mysqlx_row_fetch_one(res);
			}
		} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
		cerr << mysqlx_error_message(sess) << endl << endl;
		exit(mysqlx_error_num(sess));
	}

	delete[] query1;
}
int main() {

	int x = 1;
	int firstYear, secondYear, firstMonth, secondMonth, firstDay, secondDay, i;
	string firstDate, secondDate, buff;

	char err_msg[256] = {};
	int err_code = 0;

	//creration of an sql connection aka session to the mysql server
	mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "root", "my_db",err_msg ,&err_code);
	if (NULL == sess) {
		cerr << err_msg << endl;
		exit(1);
	}

	insert_quentitys(sess);

	while (x)
	{
		cout << "Hello welcome to music world!\n"\
			"please chose one of the actions below:\n"\
			"1.all the albums between two dates:\n"\
			"2.how many songs a certain musician recorded by between two dates:\n"\
			"3.how many albums a certain musician Participate by between two dates:\n"\
			"4.the must popular instrument:\n"\
			"5.the list of instruments in a certain album\n"\
			"6.the must busy producer between two dates:\n"\
			"7.the must popular manfacturer:\n"\
			"8.how many musicians recorded in the studio:\n"\
			"9.the musician that particpate with the most other musicians:\n"\
			"10.the must popular genre:\n"\
			"11.the must busy technician between two dates:\n"\
			"12.the first albuom that was recoreded in the studio:\n"\
			"13.all the song in serveral (2 or more) albums:\n"\
			"14.list of technician that particpate in specific album:\n"\
			"15.the musician that praticpate in the most more genre\n\n"\
			"0.EXIT:\n"\
			">";

		cin >> x;
		cout << "\n";

		switch (x)
		{
		case 1:
			cout << "please insert first date year:\n";
			cin >> firstYear;
			cout << "please insert first date month:\n";
			cin >> firstMonth;
			cout << "please insert first date day:\n";
			cin >> firstDay;
			firstDate = to_string(firstYear) + "-" + to_string(firstMonth) + "-" + to_string(firstDay);

			cout << firstDate << endl;

			cout << "please insert second date year:\n";
			cin >> secondYear;
			cout << "please insert second date month:\n";
			cin >> secondMonth;
			cout << "please insert second date day:\n";
			cin >> secondDay;
			secondDate = to_string(secondYear) + "-" + to_string(secondMonth) + "-" + to_string(secondDay);

			cout << secondDate << endl;

			queryOne(firstDate, secondDate, sess);

			break;
		case 2:
			cout << "please insert first date year:\n";
			cin >> firstYear;
			cout << "please insert first date month:\n";
			cin >> firstMonth;
			cout << "please insert first date day:\n";
			cin >> firstDay;
			firstDate = to_string(firstYear) + "-" + to_string(firstMonth) + "-" + to_string(firstDay);

			cout << "please insert second date year:\n";
			cin >> secondYear;
			cout << "please insert second date month:\n";
			cin >> secondMonth;
			cout << "please insert second date day:\n";
			cin >> secondDay;
			secondDate = to_string(secondYear) + "-" + to_string(secondMonth) + "-" + to_string(secondDay);

			queryTwo(firstDate, secondDate, sess);
			break;
		case 3:
			cout << "please insert first date year:\n";
			cin >> firstYear;
			cout << "please insert first date month:\n";
			cin >> firstMonth;
			cout << "please insert first date day:\n";
			cin >> firstDay;
			firstDate = to_string(firstYear) + "-" + to_string(firstMonth) + "-" + to_string(firstDay);

			cout << "please insert second date year:\n";
			cin >> secondYear;
			cout << "please insert second date month:\n";
			cin >> secondMonth;
			cout << "please insert second date day:\n";
			cin >> secondDay;
			secondDate = to_string(secondYear) + "-" + to_string(secondMonth) + "-" + to_string(secondDay);

			queryThird(firstDate, secondDate, sess);


			break;
		case 4:
			queryFour(sess);
			break;
		case 5:
			queryFifth(sess);
			break;
		case 6:
			cout << "please insert first date year:\n";
			cin >> firstYear;
			cout << "please insert first date month:\n";
			cin >> firstMonth;
			cout << "please insert first date day:\n";
			cin >> firstDay;
			firstDate = to_string(firstYear) + "-" + to_string(firstMonth) + "-" + to_string(firstDay);

			cout << "please insert second date year:\n";
			cin >> secondYear;
			cout << "please insert second date month:\n";
			cin >> secondMonth;
			cout << "please insert second date day:\n";
			cin >> secondDay;
			secondDate = to_string(secondYear) + "-" + to_string(secondMonth) + "-" + to_string(secondDay);

			querySixth(firstDate, secondDate, sess);
			break;
		case 7:
			querySeventh(sess);
			break;
		case 8:
			queryEigth(sess);
			break;
		case 9:
			queryNinth(sess);
			break;
		case 10:
			queryTenth(sess);
			break;
		case 11:
			cout << "please insert first date year:\n";
			cin >> firstYear;
			cout << "please insert first date month:\n";
			cin >> firstMonth;
			cout << "please insert first date day:\n";
			cin >> firstDay;
			firstDate = to_string(firstYear) + "-" + to_string(firstMonth) + "-" + to_string(firstDay);

			cout << "please insert second date year:\n";
			cin >> secondYear;
			cout << "please insert second date month:\n";
			cin >> secondMonth;
			cout << "please insert second date day:\n";
			cin >> secondDay;
			secondDate = to_string(secondYear) + "-" + to_string(secondMonth) + "-" + to_string(secondDay);

			queryEleventh(firstDate, secondDate, sess);
			break;
		case 12:
			queryTwelve(sess);
			break;
		case 13:
			queryThirteen(sess);
			break;
		case 14:
			queryFourteenth(sess);
			break;
		case 15:
			queryFifteen(sess);
			break;
		default:
			cout << "Please try again:\n\n";
			break;
		}

	}

	return 0;
}
