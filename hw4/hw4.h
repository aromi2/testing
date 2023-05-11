//Lecture: DS Chap4.Lists page9
#ifndef hw_4
#define hw_4
    typedef struct t_list_node {
        string id;
        string name;
        string age;
        string score;

        struct t_list_node *link;
    } list_node;

    class Menu
    {
        private: 
            list_node *head;
            
        public:
            Menu();
            ~Menu();
            bool IsEmpty();
            void MenuA(string name_data, string id_data, string age_data, string score_data);
            void MenuD(string id_data);
            bool Retrieve(string id_data);
            void PrintList();
            void File();

    };

#endif