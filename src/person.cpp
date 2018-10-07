#include "person.h"

bool str_isalpha(const string str){
    for(int i = 0; i < str.size(); i++)
    	if((isalpha(str[i]) == 0) || (str[i] == ' '))
    		return false;
    return true;
}

bool str_isalnum(const string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Person::Person()
  : username(""), firstname(""), lastname(""), gender(0), age(0), tagline("") {
}

Person::Person(string _username, string _firstname, string _lastname,
               int _gender, int _age, string _tagline)
  : username(_username), firstname(_firstname), lastname(_lastname),
    gender(_gender), age(_age), tagline(_tagline) {
}

string Person::get_username() {
    return username;
}
string Person::get_firstname() {
    return firstname;
}
string Person::get_lastname() {
    return lastname;
}
int Person::get_gender(){
    return gender;
}
int Person::get_age() {
    return age;
}
string Person::get_tagline() {
    return tagline;
}
string Person::get_info() {
	string ret = "";
    return ret;
}

bool Person::set_username(string _username) {
  if(_username.length()<=64 && _username.length()>0){
    if(str_isalpha(_username.front())){
      bool _containsalpha = false;
      bool _containsnum = false;
      bool _isalphanum = true;
      int i=0;
      while(i<_username.length() && _isalphanum){
        _containsalpha = isalpha(_username[i]) || _containsalpha;
        _containsnum = isdigit(_username[i]) || _containsnum;
        _isalphanum = isalpha(_username[i]) || isdigit(_username[i]);
      }
      if(_containsalpha && _containsnum && _isalphanum) username = _username;
      return _containsalpha && _containsnum && _isalphanum
    }
  }
	return false;
}

bool Person::set_firstname(string _firstname) {
	if (str_isalpha(_firstname) && _firstname.length()<=64 && _firstname != ' ') {
        firstname = _firstname;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_lastname(string _lastname) {
	if (str_isalpha(_lastname) && _lastname.length()<=64 && _lastname != ' ') {
        lastname = _lastname;
        return true;
    }
    else {
        return false;
    }
}

bool Person::set_gender(int _gender){
    if(_gender == 1 || _gender ==2){
      gender = _gender;
      return true;
    }
    return false;
}

bool Person::set_age(int _age) {
    if (_age >= 18 && _age<=100) {
        age = _age;
        return true;
    }
    else {
        return false;
    }
}
bool Person::set_tagline(string _tagline) {
    if (_tagline.length() <= 128) {
        tagline = _tagline;
        return true;
    }
    else {
        return false;
    }
}


bool Person::set_info(string _username, string _firstname, string _lastname,
                      int _age, string _tagline, int _gender) {
  if (set_username(_username))
    if(set_firstname(_firstname))
      if(set_lastname(lastname))
        if(set_age(_age))
          if(set_tagline(_tagline))
            if(set_gender(_gender))
              return true;
	return false;
}

bool Person::send_msg(Person &recipient, string msg) {
	// TODO
	// send message
  if(get_msgstat(recipient)<10){
    recipient.getmsg(msg);
    return true;
  }
	return false;
}

void Person::get_msg(string msg) {
	// TODO
	// get message
  inbox.push(msg);
  msg_stat['size']++;
}

int Person::get_msgstat(Person recipient){
  int size = recipient.msg_stat['size'];
  return size;
}

bool Person::read_msg() {
	// TODO
	// print the message if there any message inbox
  if(inbox.size()=0) return false;
  while(inbox.size()>0) {
    msg = inbox.pop();
    printf("%s\n", msg);
    msg_stat['size']--;
  }
  return true;
}
