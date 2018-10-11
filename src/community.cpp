#include "community.h"

Community::Community()
  : name(""), people(map<string,Person>()) {
}

Community::Community(string _name, map<string,Person> _people)
  : name(_name), people(_people) {
}

string Community::get_name() {
	return name;
}

bool Community::set_name(string _name) {
	//TODO
    // Community cannot have non alphnumeric characters
    for (int i = 0; i < _name.length(); i++) {
        if (!isalpha(_name[i]) && !isdigit(_name[i])) {
            return false;
        }
    }
	if (!_name.empty() &&
        _name <= 128 &&
        isdigit(_name[0])) {

        name = _name;
        return true;
    }
    return false;
}

bool Community::add_person(Person _person) {
    contact to_add(_person.get_username(), _person);

    return false;
}

// return the person object for a given username
Person& Community::get_member(string username) {
    if (people.find(username) != people.end()) {
    	return people[username];
    }
    else {
    	Person* p = new Person();
	return *p;
    }
}

list<string> Community::get_all_usernames() {
    list<string> usernames;
    // TODO
    // return all usernames of members as a list
    for(std::map<string, Person>::iterator it = people.begin(); it!=people.end(); it++){
      usernames.insert(it->first);
    }
    return usernames;
}

void Community::print_all_usernames() {
    // TODO
    map<string, Person>::iterator it;
    for (it = people.begin(); it != people.end(); it++) {
        std::cout << it->first;
    }
	// print all usernames of members to the console
}

list<Person> Community::find_member(string firstname) {
    list<Person> ret;
    //TODO
    // find users with a certain first name
    map<string, Person>::iterator it;
    for (it = people.begin(); i != people.end(); it++) {
        Person p = (it->second);
        if (!strcmp(firstname, p.get_firstname())):
            ret.insert(p);
    }
    return ret;
}

list<Person> Community::find_member(int age_lb, int age_ub) {
  list<Person> ret;
  //TODO
  // find users within certain ages [age_lb, age_ub], both lower bound and upper bound shall be inclusive
  for(std::map<string,Person>::iterator it = people.begin(); it!=people.end(); it++){
    int age = it -> second.get_age();
    if(age > age_lb && age < age_ub) ret.insert(it->second);
  }
  return ret;
}

bool Community::send_msg(list<string> usernames, string msg) {
	//TODO
	// send msg to a Person addressed by username
	// make sure the username is validated
    // send to every username, even if one is invalid
    // still return false if the above case is in effect
  list<string>::iterator it1;
  for(it1 = usernames.begin(); it1!= usernames.end(); it1++){
    list<Person> peoples = find_member(it1 -> first);
    list<Person>::iterator it2;
    if(!peoples.empty()){
      for(it2 = peoples.begin(); it2!=peoples.end(); it2++){
        it2-> first.get_msg(msg);
      }
    }
    else{
      return false
    }
  }
	return true;
}
