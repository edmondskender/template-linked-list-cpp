# Linked List in C++

Dieses Repository enthält eine C++-Implementierung einer einfach verketteten Liste (Linked List) als Template-Klasse. Diese Implementierung unterstützt grundlegende Operationen wie das Einfügen, Entfernen und Durchlaufen von Elementen sowie die Verwaltung der Speicherressourcen.

## Aufbau der Klasse

Die `linked_list`-Klasse verwendet eine innere Struktur namens `node`, um die einzelnen Knoten der Liste zu repräsentieren. Jeder Knoten enthält:
- einen Wert (`val`) vom generischen Typ `T`.
- einen Zeiger (`next`) auf den nächsten Knoten in der Liste.

Die `linked_list`-Klasse selbst enthält einen Zeiger (`head`), der auf den Anfang der Liste zeigt.

## Unterstützte Funktionen

### Konstruktoren und Destruktoren

- **linked_list()** – Standardkonstruktor, der eine leere Liste erzeugt.
- **linked_list(const T& value)** – Konstruktor, der eine Liste mit einem einzigen Element initialisiert.
- **~linked_list()** – Destruktor, der die Liste löscht und den Speicher freigibt.
- **linked_list(const linked_list& other)** – Copy-Konstruktor, der eine tiefe Kopie einer anderen Liste erstellt.
- **linked_list& operator=(const linked_list& other)** – Zuweisungsoperator, der eine andere Liste kopiert.
- **linked_list(linked_list&& other) noexcept** – Move-Konstruktor, der eine andere Liste übernimmt.
- **linked_list& operator=(linked_list&& other) noexcept** – Move-Zuweisungsoperator, der eine andere Liste übernimmt.

### Mitgliedsfunktionen

- **void clear()** – Löscht alle Elemente in der Liste.
- **void insert(size_t idx, const T& x)** – Fügt ein Element `x` an der Position `idx` ein.
- **void push_front(const T& x)** – Fügt ein Element `x` am Anfang der Liste hinzu.
- **void push_back(const T& x)** – Fügt ein Element `x` am Ende der Liste hinzu.
- **void pop_front()** – Entfernt das erste Element der Liste.
- **void pop_back()** – Entfernt das letzte Element der Liste.
- **void remove(size_t idx)** – Entfernt das Element an der Position `idx`.

### Freundfunktionen

- **friend std::ostream& operator<<(std::ostream& os, const linked_list& obj)** – Überlädt den `<<`-Operator, um die Liste im Konsolenformat anzuzeigen. Die Liste wird in folgender Form dargestellt: `[ val1 ] ---> [ val2 ] ---> ... ] ---|`.

## Beispielverwendung

```cpp
#include "linked_list.h"

int main() {
    linked_list<int> list;
    list.push_back(10);
    list.push_front(5);
    list.insert(1, 7);
    std::cout << list << std::endl;  // Ausgabe: [ 5 ] ---> [ 7 ] ---> [ 10 ] ---|

    list.pop_front();
    list.pop_back();
    list.remove(0);
    std::cout << list << std::endl;  // Ausgabe: [ ] ---|

    return 0;
}
