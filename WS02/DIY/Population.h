

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds
{
    struct population
    {
        char m_postalCode[3];
        int m_data;
    };

    

    bool load(population&);

    bool load(const char filename[]);

    void display();

    void deallocateMemory();
      void sort();

}
#endif // SDDS_POPULATION_H_