#include "graf.h"

int main() {
    int num_cities = 82;
    Graph *graph = create_graph(num_cities);
    read_graph_file("graf.txt", graph);
 
    printf("Komşuluk Listesi :\n\n");
    print_adj_list(graph);
    
    int city_plate;
    printf("\nLütfen Bilgi Almak İstediğiniz Şehir Plakasını Giriniz : ");
    scanf("%d", &city_plate);
    if(city_plate < 1 || city_plate > 81)
    {
        printf("\n\nHatalı Giriş: Beklenen Plaka Aralığı: (1 - 81)\n");
        printf("\nLütfen Bilgi Almak İstediğiniz Şehir Plakasını Tekrar Giriniz : ");
        scanf("%d", &city_plate);
        if(city_plate < 1 || city_plate > 81)
            printf("\n\nHata: Çıkış Yapılıyor...\n"); return 0;
    }
    printf("Giriş Derecesi : %d, Çıkış Derecesi : %d, ", find_in_degree(graph, city_plate), find_out_degree(graph, city_plate));
    
    printf("Toplam Kenar Sayısı : %d\n\n", count_edges(graph));
    
    printf("Gidilen Şehir(ler)i Görmek İçin Lütfen Bir Plaka Giriniz : ");
    scanf("%d", &city_plate);
    if(city_plate < 1 || city_plate > 81)
    {
        printf("\n\nHatalı Giriş: Beklenen Plaka Aralığı: (1 - 81)\n");
        printf("\nLütfen Bilgi Almak İstediğiniz Şehir Plakasını Tekrar Giriniz : ");
        scanf("%d", &city_plate);
        if(city_plate < 1 || city_plate > 81)
            printf("\n\nHata: Çıkış Yapılıyor...\n"); return 0;
    }
    reachable_cities(graph, city_plate);
    
    printf("Gelinen Şehir(ler)i Görmek İçin Lütfen Bir Plaka Giriniz : ");
    scanf("%d", &city_plate);
    if(city_plate < 1 || city_plate > 81)
    {
        printf("\n\nHatalı Giriş: Beklenen Plaka Aralığı: (1 - 81)\n");
        printf("\nLütfen Bilgi Almak İstediğiniz Şehir Plakasını Tekrar Giriniz : ");
        scanf("%d", &city_plate);
        if(city_plate < 1 || city_plate > 81)
            printf("\n\nHata: Çıkış Yapılıyor...\n"); return 0;
    }
    cities_reaching(graph, city_plate);

    return 0;
}