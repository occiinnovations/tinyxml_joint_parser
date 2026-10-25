#include <iostream>
#include "tinyxml2.h"
#include <string>
#include <vector>

using namespace tinyxml2;
using namespace std;

int main()
{

    string my_file;
    cout << "Enter the path to the URDF file: ";
    getline(cin, my_file);

    XMLDocument doc;

    XMLError function_result = doc.LoadFile(my_file.c_str());

    if (function_result != XML_SUCCESS)
    {
        cout << "Error parsing XML: " << function_result << endl;
        return 1;
    }

    int joint_count = 0;
    int link_count = 0;

    XMLElement *root = doc.RootElement();
    if (root != nullptr)
    {
        for (XMLElement *child = root->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
        {
            string element_name = child->Name();
            if (element_name == "joint")
            {
                joint_count++;

                XMLElement *axis = child->FirstChildElement("axis");
                if (axis != nullptr)

                {
                    const char *xyz = axis->Attribute("xyz");
                    if (xyz != nullptr)
                    {
                        cout << "Joint " << joint_count << " axis: " << xyz << endl;
                    }
                }
            }
            else if (element_name == "link")
            {
                link_count++;
            }
        }
        cout << "Number of joints: " << joint_count << endl;
        cout << "Number of links: " << link_count << endl;
    }
}