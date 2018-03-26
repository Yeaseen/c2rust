// TODO: test extern variables (whose definition is not here)

// forward decl
static int baz(void);
extern int baz(void);

// External function declaration
extern int main(void);

// External static global definition
const int visible_everywhere = 9;

// Internal static global defintion
static int counter;
extern int counter;

// Internal static local defintiion
int baz(void) {
  static int k = 0;
  counter++;
  return k + 1;
}

typedef struct {
  char string[3];
} StringStruct;

static const char *hello = "hello";

void entry(const unsigned buffer_size, int buffer[]) {

    if (buffer_size < 11) return;
    static const char *world = "world";

    // GH #83: Previously static structs would not propagate the
    // is_static attribute down to their string array fields
    static StringStruct Foo = {
      "foo",
    };

    buffer[0] = baz();
    buffer[1] = baz();
    buffer[2] = baz() + 1;
    buffer[baz()] = 4;


    buffer[7] = counter;
    counter--;
    baz();
    buffer[8] = counter;

    buffer[9] = hello[0];
    buffer[10] = world[1];
}
