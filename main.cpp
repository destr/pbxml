#include <google/protobuf/util/json_util.h>
#include <iostream>
#include <sstream>

#include <test/proto/addressbook.pb.h>

#include "cpp/xml_format.h"

using namespace tutorial;

int main(int argc, char** argv)
{

    AddressBook book;
    for (int i(0); i < 3; ++i) {
        Person* p = book.add_person();
        p->set_name("person_" + std::to_string(i));
        p->set_id(i);

        for (int j(0); j < 2; ++j) {
            auto phone = p->add_phone();
            phone->set_type(Person::WORK);

            phone->set_number("phone_" + std::to_string(i) + "_" + std::to_string(j));
        }
        p->set_awesome(i % 2);
    }

    std::string output;
    google::protobuf::XmlFormat::PrintToXmlString(book, &output);

    std::cout << output << std::endl;

    AddressBook book2;
    google::protobuf::XmlFormat::MessageFromDOM(output, &book2);

    std::cout << book2.DebugString() << std::endl;

    return 0;
}
