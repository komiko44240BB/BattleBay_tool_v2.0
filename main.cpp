#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <iostream>

void choice_callback(Fl_Widget* widget, void* data) {
    Fl_Choice* choice = (Fl_Choice*)widget;
    std::cout << "Vous avez sélectionné : " << choice->text(choice->value()) << std::endl;
}

int main() {
    // Créer une fenêtre
    Fl_Window* window = new Fl_Window(400, 300, "Liste déroulante avec FLTK");

    // Définir la couleur de fond de la fenêtre
    window->color(FL_WHITE);

    // Créer un groupe pour organiser les widgets
    Fl_Group* group = new Fl_Group(20, 20, 360, 260);
    group->box(FL_UP_BOX);
    group->color(FL_LIGHT2);

    // Créer une étiquette
    Fl_Box* label = new Fl_Box(20, 20, 360, 30, "Sélectionnez une option :");
    label->labelsize(16);
    label->labelcolor(FL_DARK_BLUE);
    label->align(FL_ALIGN_CENTER);

    // Créer une liste déroulante
    Fl_Choice* choice = new Fl_Choice(50, 70, 300, 30);
    choice->add("Option 1");
    choice->add("Option 2");
    choice->add("Option 3");
    choice->add("Option 4");
    choice->value(0); // Sélectionner la première option par défaut
    choice->color(FL_WHITE); // Couleur de fond de la liste déroulante

    // Ajouter un bouton pour valider la sélection
    Fl_Button* button = new Fl_Button(150, 120, 100, 30, "Valider");
    button->callback(choice_callback, choice);

    // Afficher le groupe et la fenêtre
    group->end();
    window->end();
    window->show();

    return Fl::run();
}