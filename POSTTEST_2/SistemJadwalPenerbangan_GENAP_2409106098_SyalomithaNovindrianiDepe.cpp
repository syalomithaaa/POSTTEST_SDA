#include <iostream>
#include <iomanip>
using namespace std;

// warna
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define PINK    "\033[35m"  

// data penerbangan
struct JadwalPenerbangan {
    string kodePenerbangan;
    string maskapai;
    string tujuan;
    string waktu;
    string status;
};

// linked List
struct Node {
    JadwalPenerbangan jadwal;
    Node* next;
};

// node baru
Node* buatNode(string kode, string maskapai, string tujuan, string waktu, string status) {
    Node* newNode = new Node;
    newNode->jadwal = {kode, maskapai, tujuan, waktu, status};
    newNode->next = nullptr;
    return newNode;
}

// di akhir linked list
void tambahJadwal(Node*& head, string kode, string maskapai, string tujuan, string waktu, string status) {
    Node* newNode = buatNode(kode, maskapai, tujuan, waktu, status);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
}

// sisip di posisi tertentu
void sisipkanJadwal(Node*& head, int posisi, string kode, string maskapai, string tujuan, string waktu, string status) {
    Node* newNode = buatNode(kode, maskapai, tujuan, waktu, status);

    if (posisi == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < posisi - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << RED << "Posisi tidak valid!" << RESET << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// hapus node pertama
void hapusJadwalPertama(Node*& head) {
    if (head == nullptr) {
        cout << RED << "Tidak ada jadwal untuk dihapus!" << RESET << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << GREEN << "Jadwal paling awal berhasil dihapus." << RESET << endl;
}

// update status penerbangan
void updateStatus(Node* head, string kode, string statusBaru) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->jadwal.kodePenerbangan == kode) {
            temp->jadwal.status = statusBaru;
            cout << GREEN << "Status penerbangan berhasil diperbarui." << RESET << endl;
            return;
        }
        temp = temp->next;
    }
    cout << RED << "Jadwal dengan kode tersebut tidak ditemukan!" << RESET << endl;
}

// menu + jadwal dalam satu blok
void tampilkanMenuDanJadwal(Node* head) {
    cout << PINK << "\n====================================================\n";
    cout << "              SISTEM JADWAL PENERBANGAN\n"; 
    cout << "      (Syalomitha Novindriani Depe - 2409106098)\n"; 
    cout << "====================================================" << RESET << endl;

    cout << CYAN << "\nMenu:\n" << RESET;
    cout << "1. Tambah Jadwal\n";
    cout << "2. Sisipkan Jadwal (posisi 9)\n";
    cout << "3. Hapus Jadwal Paling Awal\n";
    cout << "4. Update Status Penerbangan\n";
    cout << "5. Tampilkan Semua Jadwal\n";
    cout << "0. Keluar\n";

    cout << PINK
         << "\n+---------------+--------------------+--------------------+---------------+---------------+" << endl;
    cout << "| " << left << setw(13) << "Kode"
         << "| " << setw(18) << "Maskapai"
         << "| " << setw(18) << "Tujuan"
         << "| " << setw(13) << "Waktu"
         << "| " << setw(13) << "Status" << "|" << endl;
    cout << "+---------------+--------------------+--------------------+---------------+---------------+" 
         << RESET << endl;

    if (head == nullptr) {
        cout << "| " << setw(83) << RED "Belum ada jadwal penerbangan" RESET << "|\n";
    } else {
        Node* current = head;
        while (current != nullptr) {
            cout << "| " << left << setw(13) << current->jadwal.kodePenerbangan
                 << "| " << setw(18) << current->jadwal.maskapai
                 << "| " << setw(18) << current->jadwal.tujuan
                 << "| " << setw(13) << current->jadwal.waktu;

            if (current->jadwal.status == "OnTime" || current->jadwal.status == "On_Time")
                cout << "| " << GREEN << setw(13) << current->jadwal.status << RESET << "|" << endl;
            else if (current->jadwal.status == "Delayed")
                cout << "| " << RED << setw(13) << current->jadwal.status << RESET << "|" << endl;
            else
                cout << "| " << YELLOW << setw(13) << current->jadwal.status << RESET << "|" << endl;

            current = current->next;
        }
    }

    cout << PINK
         << "+---------------+--------------------+--------------------+---------------+---------------+" 
         << RESET << endl;
}

int main() {
    Node* head = nullptr;
    int pilihan;
    int nomorUrut = 0;
    string kodeBase = "JT-098"; // (098 → kode dasar)

    do {
        tampilkanMenuDanJadwal(head);

        cout << "\nPilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            nomorUrut++;
            string kode = kodeBase + "-" + to_string(nomorUrut);
            string maskapai, tujuan, waktu, status;
            cout << "Maskapai: "; cin >> maskapai;
            cout << "Tujuan: "; cin >> tujuan;
            cout << "Waktu: "; cin >> waktu;
            cout << "Status (OnTime/Delayed/Cancelled): "; cin >> status;
            tambahJadwal(head, kode, maskapai, tujuan, waktu, status);
        } 
        else if (pilihan == 2) {
            nomorUrut++;
            string kode = kodeBase + "-" + to_string(nomorUrut);
            string maskapai, tujuan, waktu, status;
            cout << "Maskapai: "; cin >> maskapai;
            cout << "Tujuan: "; cin >> tujuan;
            cout << "Waktu: "; cin >> waktu;
            cout << "Status (OnTime/Delayed/Cancelled): "; cin >> status;
            sisipkanJadwal(head, 9, kode, maskapai, tujuan, waktu, status);
        } 
        else if (pilihan == 3) {
            hapusJadwalPertama(head);
        } 
        else if (pilihan == 4) {
            string kode, statusBaru;
            cout << "Masukkan kode penerbangan: ";
            cin >> kode;
            cout << "Status baru: ";
            cin >> statusBaru;
            updateStatus(head, kode, statusBaru);
        } 
        else if (pilihan == 5) {
        
        } 
        else if (pilihan == 0) {
            cout << GREEN << "Keluar dari program." << RESET << endl;
        } 
        else {
            cout << RED << "Pilihan tidak valid!" << RESET << endl;
        }

    } while (pilihan != 0);

    return 0;
}
