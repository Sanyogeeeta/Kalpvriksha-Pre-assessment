#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int top;
    int capacity;
    char **history;
} TextEditor;

void init_text_editor(TextEditor *editor, int capacity) {
    editor->str = (char *)malloc(1000001 * sizeof(char));
    editor->history = (char **)malloc(capacity * sizeof(char *));
    editor->str[0] = '\0';
    editor->top = -1;
    editor->capacity = capacity;
}

int is_empty(TextEditor *editor) {
    return editor->top == -1;
}

void push(TextEditor *editor, char *state) {
    if (editor->top < editor->capacity - 1) {
        editor->history[++(editor->top)] = strdup(state);
    }
}

void pop(TextEditor *editor) {
    if (!is_empty(editor)) {
        free(editor->history[editor->top]);
        editor->top--;
    }
}

void append(TextEditor *editor, char *input) {
    int len = strlen(editor->str);
    strcat(editor->str, input);
    push(editor, editor->str);
}

void delete(TextEditor *editor, int k) {
    int len = strlen(editor->str);
    editor->str[len - k] = '\0';
    push(editor, editor->str);
}

void undo(TextEditor *editor) {
    if (!is_empty(editor)) {
        pop(editor);
    }
}

void print_char(TextEditor *editor, int k) {
    int len = strlen(editor->str);
    if (k <= len) {
        printf("%c\n", editor->str[k - 1]);
    } else {
        printf("Invalid position\n");
    }
}

int main() {
    int q;
    scanf("%d", &q);

    TextEditor editor;
    init_text_editor(&editor, q);

    while (q--) {
        int operation;
        scanf("%d", &operation);

        switch (operation) {
            case 1: {
                char input[1000001];
                scanf("%s", input);
                append(&editor, input);
                break;
            }
            case 2: {
                int k;
                scanf("%d", &k);
                delete(&editor, k);
                break;
            }
            case 3: {
                int k;
                scanf("%d", &k);
                print_char(&editor, k);
                break;
            }
            case 4: {
                undo(&editor);
                break;
            }
            default:
                break;
        }
    }

    while (!is_empty(&editor)) {
        pop(&editor);
    }

    free(editor.str);
    free(editor.history);

    return 0;
}
