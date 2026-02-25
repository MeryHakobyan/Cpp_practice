#include <iostream>
#include <vector>

class Book{
private:
    std::string m_name;
    std::string m_author;
    int m_id;
public:
    Book(const std::string &name, const std::string author, int id) : m_name(name), m_author(author), m_id{id} {
   }  
   void setName(const std::string &name){
        m_name = name;
   }
   void setAuthor(const std::string &author){
        m_author = author;
   }
   void setId(int id){
        m_id = id;
   }
   std::string getName() const {
        return m_name;
   }
   std::string getAuthor() const {
        return m_author;
   }
   int getId() const {
        return m_id;
   }
};

class Library{
private:
    std::vector<Book> books;
public:
    Library() = default;

    void addBooks(const Book &book){
        books.push_back(book);      
    }

    void listBooks() const {
        for(int i = 0; i<books.size(); i++) {
            std::cout << books[i].getName() << std::endl;
        }
    }

    Book *findBookByName(const std::string &name){
        for(int i = 0; i<books.size(); i++){
             if(name == books[i].getName()){
                return  &books[i];
             }
        }
        return nullptr;
    }

};

int main(){
    Book b("name1", "author1", 1);
    Book d("name2", "author2", 2);
    Library l;
    l.addBooks(b);
    l.addBooks(d);
    l.listBooks();
    Book *ret = l.findBookByName("name3");
    if (ret) {
        std::cout << ret->getId();
    }
    else {
        std::cout << "there is no book with that name\n";
    }


}
