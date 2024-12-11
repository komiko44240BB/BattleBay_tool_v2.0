#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_PNG_Image.H>
#include <string>
#include <vector>
#include <map>

// Callback function to handle list selections
void choice_cb(Fl_Widget* widget, void* data) {
    Fl_Choice* choice = (Fl_Choice*)widget;
    std::map<std::string, std::string>* selections = (std::map<std::string, std::string>*)data;

    std::string list_name = choice->label();
    std::string selected_value = choice->text();
    (*selections)[list_name] = selected_value;

    // Example: Print the selection
    printf("List %s: Selected %s\n", list_name.c_str(), selected_value.c_str());
}

int main() {
    // Main window
    Fl_Window* window = new Fl_Window(820, 400, "Dynamic UI Example");

    // Image placeholder
    Fl_PNG_Image* background_image = new Fl_PNG_Image("background.png");
    Fl_Box* image_box = new Fl_Box(20, 20, 64, 64, "Image");
    image_box->image(background_image);
    image_box->box(FL_UP_BOX);

    // Value placeholders
    int x_offset = 240;
    int y_offset = 20;
    std::vector<Fl_Output*> value_placeholders;

    // List of labels for the value outputs
    std::vector<std::string> value_labels = {
        "Base stat", "Cool down", "Range", "Projectile speed",
        "Duration", "Radius", "Crit hit chance", "Crit hit multiplier", "Combo damage"
    };

    for (int i = 0; i < 7; ++i) {
        // Label above each Fl_Output
        Fl_Box* value_label = new Fl_Box(x_offset, y_offset, 100, 20, value_labels[i].c_str());
        value_label->align(FL_ALIGN_CENTER);

        // Fl_Output placeholder
        Fl_Output* value_output = new Fl_Output(x_offset, y_offset + 20, 100, 30);
        value_output->value("N/A");
        value_placeholders.push_back(value_output);
        y_offset += 60;
        if ((i + 1) % 2 == 0) { // Layout adjustment
            x_offset += 120;
            y_offset = 20;
        }
    }

    // Labels for lists
    std::vector<std::string> labels = {
        "Object type", "Rarity", "Name", "Object level",
        "Training level", "Perk 1", "Perk 2", "Perk 3", "Perk 4"
    };

    // List placeholders with text above
    x_offset = 20;
    y_offset = 200; // Starting position
    int list_width = 150; // Width of each list
    int list_height = 30; // Height of each list
    int spacing = 10; // Space between lists
    int label_height = 20; // Height of the labels
    std::vector<Fl_Choice*> lists;
    std::map<std::string, std::string> selections; // Track user selections

    for (int i = 0; i < 9; ++i) {
        // Add the label above the list
        Fl_Box* label_box = new Fl_Box(x_offset, y_offset, list_width, label_height, labels[i].c_str());
        label_box->align(FL_ALIGN_CENTER);

        // Add the list itself
        Fl_Choice* choice = new Fl_Choice(x_offset, y_offset + label_height + spacing, list_width, list_height);

        // Example initial items
        choice->add("Option A");
        choice->add("Option B");
        choice->add("Option C");
        choice->callback(choice_cb, &selections);

        lists.push_back(choice);

        // Adjust position for the next list
        x_offset += list_width + spacing;
        if ((i + 1) % 5 == 0) { // Move to the next row after 4 lists
            x_offset = 20; // Reset x position
            y_offset += label_height + list_height + 2 * spacing;
        }
    }

    // Make everything visible
    window->end();
    window->show();

    return Fl::run();
}
