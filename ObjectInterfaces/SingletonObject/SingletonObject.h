/**
 * @file SingletonObject.h
 * @author  Sacco Cosimo <cosimosacco@gmail.com>, Silvestri Davide <davidesil.web@gmail.com>
 *
 * @section LICENSE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SINGLETONOBJECT_H
#define SINGLETONOBJECT_H

#include <boost/thread/mutex.hpp>
#include <boost/pool/detail/guard.hpp>
#include <cstdlib>

/**
 * @class SingletonObject
 *
 * @brief Interfaccia template per singoletti.
 *
 * Le classi che implementano l' interfaccia SingletonObject possono essere istanziate una sola volta, secondo il design pattern Singleton.
 */

template <typename T>
void singletonMemoryHandler();

template <typename T>
class SingletonObject
{
private:
    static T* instance;
    static boost::mutex lifecycleControl;
	/**
	 * Costruttore privato: non è possibile istanziare direttamente oggetti di classi che implementano l'interfaccia SingletonObject.
     */
    SingletonObject() {}
	/**
	 * Distruttore privato: non è possibile distruggere direttamente oggetti di classi che implementano l'interfaccia SingletonObject.
     */
    ~SingletonObject() {}
public:
	/**
	 * Crea un' istanza statica della classe desiderata, se non ne esiste già una, e la ritorna al chiamante.
     * La creazione è protetta da una guardia di mutua esclusione. Inoltre, viene registrato un handler
     * che provvederà a liberare la memoria dinamica occupata dal singleton in
     * conseguenza dell' invocazione di void exit(int status).
     *
     * @return Puntatore alla istanza singleton della classe desiderata.
     */
    static T* getInstance()
    {
        boost::details::pool::guard<boost::mutex> lifecycleGuard(lifecycleControl);
        if(instance == NULL)
        {
            instance = new T();
            atexit(singletonMemoryHandler<T>);
        }
        return instance;
    }
	/**
	 * Distrugge l'istanza singleton.
	 * La distruzione è protetta da una guardia di mutua esclusione.
	 * Deve valere la precondizione che il thread invocante questo metodo
	 * deve essere l' unico owner dell' istanza da distruggere. Qualora
	 * tale precondizione non fosse verificata, l' oggetto potrebbe essere
	 * lasciato in uno stato incoerente. Ad esempio, se il thread A ottiene
	 * il puntatore all' istanza ma questa viene distrutta dal thread B
	 * prima che A la utilizzi, A avrà un puntatore non valido che,
	 * dereferenziato, produrrà un errore di segmentazione.
	 * La distruzione di un singleton, va effettuata solo essendo verificata
	 * la precondizione di cui sopra. Lasciare che il singleton venga deallocato
	 * dal singletonMemoryManager registrato con atexit(void (*function)(void))
	 * al momento della creazione é la scelta più semplice e sicura.
	 * @pre Il thread che invoca il metodo deve essere l' unico owner del singleton.
     */
    static void destroyInstance()
    {
        boost::details::pool::guard<boost::mutex> lifecycleGuard(lifecycleControl);
        delete instance;
        instance = NULL;
    }
};

template <typename T>
void singletonMemoryHandler()
{
    SingletonObject<T>::destroyInstance();
}

/* Inizializzazione membri statici. */
template <typename T> T* SingletonObject<T>::instance = NULL;
template <typename T> boost::mutex SingletonObject<T>::lifecycleControl;

#endif //SINGLETONOBJECT_H
