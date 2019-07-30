#include <mysqlx/xapi.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


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













	/*
	char err_msg[256] = {};
	mysqlx_error_t** err_code = 0;

	//creration of an sql connection aka session to the mysql server
	mysqlx_session_t* sess = mysqlx_get_session("localhost", DEFAULT_MYSQLX_PORT, "root", "root", "studio",err_code);
	if (NULL == sess) {
	cerr << err_msg << endl;
	exit(1);
	}

	char query1[] = { "show tables" };

	mysqlx_result_t* res = mysqlx_sql(sess, query1, MYSQLX_NULL_TERMINATED);

	if (NULL != res) {
	char buff[256]; size_t size = 0;

	do {
	mysqlx_row_t* row = mysqlx_row_fetch_one(res);
	while (NULL != row) {
	size = sizeof(buff);
	mysqlx_get_bytes(row, 0, 0, buff, &size);
	cout << buff << endl;
	row = mysqlx_row_fetch_one(res);
	}
	} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
	cerr << mysqlx_error_message(sess) << endl;
	exit(mysqlx_error_num(sess));
	}

	cout << "------------------------" << endl;

	char query2[] = {
	"SELECT actor_id, first_name, last_name, concat(last_update,'') as last_update "\
	"FROM `actor` "\
	"WHERE actor_id > ?;"
	};

	//res = mysqlx_sql(sess, query2, MYSQLX_NULL_TERMINATED);
	mysqlx_stmt_t* stmt = mysqlx_sql_new(sess, query2, MYSQLX_NULL_TERMINATED);
	if (RESULT_OK != mysqlx_stmt_bind(stmt, PARAM_SINT(100), PARAM_END)) {
	cerr << "error binding parameters\n";
	exit(2);
	}
	res = mysqlx_execute(stmt);

	if (NULL != res) {
	char buff[256]; size_t size = 0;
	uint32_t cols = mysqlx_column_get_count(res);

	do {
	mysqlx_row_t* row = mysqlx_row_fetch_one(res);
	while (NULL != row) {
	for (uint32_t i = 0; i < cols; ++i) {
	int64_t id;
	size = sizeof(buff);
	if (i > 0)
	mysqlx_get_bytes(row, i, 0, buff, &size);
	else mysqlx_get_sint(row, 0, &id);

	switch (i) {
	case 0:
	/*id = 0;
	memcpy(&id, buff, size);*/

	/*cout << id;
	break;
	case 1:
	case 2:
	case 3:
	cout << buff;
	break;
	default:
	cout << "undefined";
	}
	if (9 > size)
	cout << "\t";
	cout << "\t|\t";
	}
	cout << endl;
	row = mysqlx_row_fetch_one(res);
	}
	} while (RESULT_OK == mysqlx_next_result(res));
	}
	else {
	cerr << mysqlx_error_message(sess) << endl;
	exit(mysqlx_error_num(sess));
	}

	mysqlx_session_close(sess);

	getchar();*/
	return 0;
}