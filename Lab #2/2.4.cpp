// Să se scrie o clasă Mail_box cu datele membre email și capacitate (numărul maxim de mesaje ce pot fi stocate <= 10). Aceasta va conține și un vector de obiecte din clasa Mail. Clasa Mail conține următoarele date membre de tipul std::string: sender, recipient, subject și body. Se vor citi de la tastatură, în ordine, următoarele informații:
// un șir de caractere reprezentând adresa de email proprie;
// un întreg reprezentând capacitatea maximă de stocare;
// un întreg reprezentând numărul de mesaje primite. Pentru fiecare mesaj primit se citesc următoarele date:
// adresa de email a expeditorului;
// adresa de email a destinatarului;
// subiectul mesajului;
// corpul mesajului;
// un întreg reprezentând o comandă, în funcție de care se vor executa diferite funcționalități:
// check_inbox - se afișează toate mesajele destinate adresei reținute în obiectul Mail_box, în ordinea în care au fost introduse de la tastatură. Afișarea unui // mesaj presupune afișarea următoarelor informații pe ecran, pe linii separate:
// Index:<index-ul din lista de mesaje>
// From:<sender>
// To:<recipient>
// Subject:<subject>
// Body:<body>
// ---
// check_outbox - se afișează toate mesajele trimise de către adresa reținută în obiectul Mail_box, în ordinea în care au fost trimise.
// send - se citesc datele (fără expeditor) pentru un obiect Mail care va fi trimis către destinatar. Ulterior, se afișează pe ecran mesajele trimise.
// reply - se citește de la tastatură un întreg reprezentând indexul mesajului din lista de mesaje din inbox căruia dorim să ii răspundem. Se citesc datele (subiectul si corpul mesajului) pentru un obiect Mail nou care va fi trimis ca răspuns pentru mesajul selectat. Ulterior, se afișează pe ecran mesajele trimise.
// forward - se citește de la tastatură un întreg reprezentând indexul mesajului din lista de mesaje din inbox pe care dorim să îl redirecționăm. Se citește de la tastatură doar adresa de email către care facem redirecționarea, corpul și subiectul mesajului fiind preluate de la mesajul din inbox. Ulterior, se afișează pe ecran mesajele trimise.


#include <iostream>
#include <string>

class Mail{
    private:
        std::string sender;
        std::string recipient;
        std::string subject;
        std::string body;
    public:
        std::string get_sender(){
            return sender;
        }
        std::string get_recipient(){
            return recipient;
        }
        std::string get_subject(){
            return subject;
        }
        std::string get_body(){
            return body;
        }
        Mail(std::string sender="",std::string recipient="",std::string subject="",std::string body=""):sender(sender),recipient(recipient),body(body),subject(subject){}
        void display(){
            std::cout << "From:" << sender << std::endl;
            std::cout << "To:" << recipient << std::endl;
            std::cout << "Subject:" << subject << std::endl;
            std::cout << "Body:" << body << std::endl;
            std::cout << "---" << std::endl;
        }
        
};
class Mail_box{
    private:
        std::string email;
        int capacitate;
        Mail **arhiva;
        
    public:
    Mail_box(int capacitate = 0):capacitate(capacitate){
        arhiva = new Mail*[capacitate];
    }
    
    void set_mail(int x, std::string sender="",std::string recipient="",std::string subject="",std::string body=""){
        arhiva[x] = new Mail(sender,recipient,subject,body);
    }
    void inbox_check(std::string adresa, int nr, int contor){
        for(int i = 0 ; i < nr ; ++i){
            if((arhiva[i]->get_recipient() == adresa) && (contor == 1)){
                std::cout << "Index:" << i << std::endl;
                arhiva[i]->display();
            }
            else if((arhiva[i]->get_sender() == adresa) && (contor == 2)){
                std::cout << "Index:" << i << std::endl;
                arhiva[i]->display();
            }
            
        }
    }
    
    void afisare_mail(int x){
        arhiva[x]->display();
    }
    ////////////////////////////////////////////////////////////////////////////////////////ex4
    
    std::string get_sender4(int x){
        return arhiva[x]->get_sender();
    }
    void afisare4(int nr, std::string a){
        for(int i = 0 ; i < nr ; ++i)
            if(arhiva[i]->get_sender() == a)
                std::cout << "Index:" << i << std::endl, arhiva[i]->display();
    }
    ////////////////////////////////////////////////////////////////////////////////////////ex5
    std::string get_subject5(int x){
        return arhiva[x]->get_subject();
    }
    std::string get_body5(int x){
        return arhiva[x]->get_body();
    }
    
};

int main(){
    std::string temp_email;
    int max_capacitate;
    int nr_mesaje;
    int test;
    
    std::string temp_adresae, temp_adresad, temp_subiect, temp_corp;
    std::getline(std::cin, temp_email);
    std::cin >> max_capacitate >> nr_mesaje;
    Mail_box box(max_capacitate);
    std::cin.ignore();
    for(int i = 0 ; i < nr_mesaje ; i++){
        
        std::getline(std::cin, temp_adresae);
        std::getline(std::cin, temp_adresad);
        std::getline(std::cin, temp_subiect);
        std::getline(std::cin, temp_corp);
        box.set_mail(i,temp_adresae,temp_adresad, temp_subiect, temp_corp);
    }
    
    std::cin >> test;
    switch(test){
        case 1: box.inbox_check(temp_email,nr_mesaje,1);
                break;
        case 2: box.inbox_check(temp_email,nr_mesaje,2);
                break;
        case 3: {
                    Mail_box temp_box;
                    std::cin.ignore();
                    std::getline(std::cin, temp_adresad);
                    std::getline(std::cin, temp_subiect);
                    std::getline(std::cin, temp_corp);
                    temp_box.set_mail(0,temp_email, temp_adresad, temp_subiect, temp_corp);
                    box.inbox_check(temp_email, nr_mesaje,2);
                    std::cout << "Index:" << nr_mesaje << std::endl;
                    temp_box.afisare_mail(0);
                    break;
        }
         case 4: {
                    Mail_box temp_box;
                    int index;
                    std::cin >> index;
                    std::cin.ignore();
                    std::getline(std::cin, temp_subiect);
                    std::getline(std::cin, temp_corp);
                    temp_box.set_mail(0,temp_email,box.get_sender4(index),temp_subiect,temp_corp);
                    box.afisare4(nr_mesaje, temp_email);
                    std::cout << "Index:" << nr_mesaje << std::endl;
                    temp_box.afisare_mail(0);
                    break;
         }
         case 5: {
                    Mail_box temp_box;
                    std::string temp_email2;
                    int index;
                    std::cin >> index;
                    std::cin.ignore();
                    std::getline(std::cin, temp_email2);
                    box.inbox_check(temp_email, nr_mesaje, 2);
                    temp_box.set_mail(0,temp_email,temp_email2,box.get_subject5(index),box.get_body5(index));
                    std::cout << "Index:" << nr_mesaje << std::endl;
                    temp_box.afisare_mail(0);
                    break;
                    
                    
         }
                
       }
    return 0;
}
