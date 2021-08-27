#include "ComparisonLists.hpp"
using namespace std;

int main(){

    Node* firstNode; //parametreye vermek için düğüm olusturdum
    Node* secondNode;

    ComparisonList *comp = new ComparisonList(); //ComparisonList sınıfımdan nesne olusturdum
    comp->ComparisonProccess(firstNode,secondNode); //karşılaştırma işlemleri yapan metodu çağırdım
    delete(comp); //oluşturdugum çöpü sildim
    return 0;
}
