import java.util.*;

class AutocompleteSystem {

    // =========================================================
    // THINK OF THIS LIKE GOOGLE SEARCH
    // When you type "i" in google, it shows suggestions below
    // "i love you", "island", "iroman" etc.
    // We need to build exactly that.
    // =========================================================


    // =========================================================
    // WHAT IS A TRIE NODE?
    // Think of a city with many streets.
    // The city has a main square (root).
    // From main square, streets go in all directions.
    // Each street has a NAME (one character like 'i', 's', 'a')
    // Each street also has a REGISTER (notebook)
    // That register says: "which sentences passed through this street?"
    //
    // Example:
    // Main Square → "i" street → "is" street → "isl" street → ...
    //
    // The "i" street's register says:
    //   "i love you"      → 5 times
    //   "island"          → 3 times
    //   "i love leetcode" → 2 times
    //
    // So when user types "i", we go to "i" street,
    // open its register, and show top 3 results!
    // =========================================================

    class TrieNode {

        // This map stores: "which streets can we go to from here?"
        // Key   = the next character (like 'i', 's', ' ')
        // Value = the next TrieNode (the next street)
        //
        // Example: if we are at "i" node,
        // children might have:
        //   's' → (node for "is")
        //   ' ' → (node for "i ")
        //   'r' → (node for "ir")
        Map<Character, TrieNode> children = new HashMap<>();

        // This map is the REGISTER of this street.
        // It stores: which sentences passed through here, and how many times
        // Key   = the full sentence (like "i love you")
        // Value = how many times it was searched (like 5)
        //
        // Example: the register at "i " node has:
        //   "i love you"      → 5
        //   "i love leetcode" → 2
        // (only sentences starting with "i " are here)
        Map<String, Integer> sentences = new HashMap<>();
    }


    // =========================================================
    // THESE ARE OUR GLOBAL VARIABLES
    // They are remembered throughout the whole program
    // =========================================================

    // This is the ROOT of our trie - the main square of the city
    // Every search starts from here
    private TrieNode root;

    // This is like a POINTER - it says "which street are we standing on right now?"
    // When user types 'i', we move this pointer to the "i" street
    // When user types 's' next, we move it to the "is" street
    // When user types '#', we reset it back to root (main square)
    private TrieNode currentNode;

    // This stores whatever the user has typed so far in this session
    // Example: user typed 'i', then ' ', then 'l'
    // currentInput will be "i l"
    // We use StringBuilder instead of String because:
    //   String is IMMUTABLE in Java - every time you add a letter,
    //   it creates a brand new String object in memory (slow and wasteful)
    //   StringBuilder is MUTABLE - it just appends to existing object (fast)
    private StringBuilder currentInput;


    // =========================================================
    // CONSTRUCTOR
    // This runs ONCE when the object is first created
    // It sets up everything and loads all the initial sentences
    // =========================================================

    public AutocompleteSystem(String[] sentences, int[] times) {

        // Create the main square (root node) - empty city, no streets yet
        root = new TrieNode();

        // We start standing at the main square
        currentNode = root;

        // Nothing has been typed yet
        currentInput = new StringBuilder();

        // Now load all the sentences that were previously searched
        // sentences[i] was searched times[i] number of times
        // We insert each one into our trie (build the streets + fill registers)
        for (int i = 0; i < sentences.length; i++) {
            insert(sentences[i], times[i]);
        }
    }


    // =========================================================
    // INSERT METHOD
    // This takes one sentence and puts it inside the trie
    // It walks from the root, creating streets if they don't exist,
    // and writes this sentence in the register of EVERY street it passes through
    //
    // WHY write in every street's register?
    // Because when user types just "i", we open "i" street's register
    // and we need to already know ALL sentences starting with "i"
    // We don't want to search again at that point - it should be instant!
    // =========================================================

    private void insert(String sentence, int freq) {

        // Always start from the root (main square)
        TrieNode node = root;

        // Go through the sentence character by character
        // Example: "island" → 'i', 's', 'l', 'a', 'n', 'd'
        for (char ch : sentence.toCharArray()) {

            // Does a street exist for this character?
            // If NOT, create a new street (new TrieNode)
            // putIfAbsent means: "put this only if key is absent (not already there)"
            node.children.putIfAbsent(ch, new TrieNode());

            // Now walk INTO that street (move our pointer forward)
            node = node.children.get(ch);

            // IMPORTANT: Write this sentence in THIS street's register
            // getOrDefault(sentence, 0) means:
            //   "get the current count of this sentence"
            //   "if it's not there yet, return 0 (default)"
            // Then we add freq to whatever we got
            //
            // Example: inserting "island" with freq=3
            //   At "i"   node → sentences["island"] = 0 + 3 = 3
            //   At "is"  node → sentences["island"] = 0 + 3 = 3
            //   At "isl" node → sentences["island"] = 0 + 3 = 3
            //   ... and so on until 'd'
            node.sentences.put(
                sentence,
                node.sentences.getOrDefault(sentence, 0) + freq
            );
        }
    }


    // =========================================================
    // INPUT METHOD
    // This is called every time the user types ONE character
    // It either:
    //   1. Returns top 3 suggestions (for normal characters)
    //   2. Saves the sentence and resets (for '#' character)
    // =========================================================

    public List<String> input(char c) {

        // ======================
        // CASE 1: User typed '#'
        // This means the sentence is complete (like pressing Enter)
        // ======================
        if (c == '#') {

            // Save whatever was typed into our trie with frequency 1
            // (user searched this sentence 1 new time)
            insert(currentInput.toString(), 1);

            // Clear the input - new search session starts fresh
            currentInput = new StringBuilder();

            // Go back to main square (root) for next search
            currentNode = root;

            // Return empty list - no suggestions needed when sentence ends
            return new ArrayList<>();
        }


        // ======================
        // CASE 2: Normal character typed (a letter or space)
        // ======================

        // Add this character to what user has typed so far
        // Example: user typed 'i' before, now types ' '
        // currentInput goes from "i" to "i "
        currentInput.append(c);

        // Check if the next street exists for this character
        // currentNode == null means we already hit a dead end before
        //   (no sentences matched the previous prefix)
        //   so no point checking further
        // !currentNode.children.containsKey(c) means
        //   this street simply doesn't exist
        //   (no sentence ever started with this prefix)
        if (currentNode == null || !currentNode.children.containsKey(c)) {

            // Mark as dead end - no future characters will match either
            // We set currentNode to null so next calls also return empty fast
            currentNode = null;
            return new ArrayList<>();
        }

        // Street exists! Walk into it.
        // Move our pointer to the next node
        currentNode = currentNode.children.get(c);

        // =====================================================
        // NOW WE HAVE REACHED THE RIGHT STREET
        // Open its register and get all sentences stored there
        // =====================================================

        // Get all entries from the register
        // Each entry is: (sentence → frequency)
        // Example: [("i love you", 5), ("i love leetcode", 2)]
        List<Map.Entry<String, Integer>> candidates =
            new ArrayList<>(currentNode.sentences.entrySet());

        // SORT the candidates by two rules:
        // RULE 1 (primary)   → Higher frequency comes FIRST
        //                      (most searched = most popular = show first)
        // RULE 2 (secondary) → If frequency is same, alphabetical order
        //                      (smaller ASCII value = earlier in alphabet = first)
        //
        // The lambda (a, b) -> {...} is a custom comparator
        // It compares two entries a and b and decides which comes first
        // If result is NEGATIVE → a comes first
        // If result is POSITIVE → b comes first
        // If result is ZERO     → they are equal
        candidates.sort((a, b) -> {

            // Are the frequencies different?
            if (!a.getValue().equals(b.getValue())) {
                // b - a gives DESCENDING order (bigger number first)
                // Example: a=2, b=5 → 5-2=3 (positive) → b comes first ✓
                return b.getValue() - a.getValue();
            }

            // Frequencies are same → sort alphabetically
            // compareTo returns negative if a comes before b alphabetically
            // Example: "apple".compareTo("banana") → negative → apple first ✓
            return a.getKey().compareTo(b.getKey());
        });

        // Pick only the TOP 3 results
        // Math.min(3, candidates.size()) handles the case when
        // there are less than 3 candidates (we don't want IndexOutOfBounds error)
        List<String> result = new ArrayList<>();
        for (int i = 0; i < Math.min(3, candidates.size()); i++) {
            result.add(candidates.get(i).getKey());
        }

        // Return the top 3 suggestions to show to the user
        return result;
    }
}

// =========================================================
// FULL EXAMPLE WALKTHROUGH
//
// Initial sentences: ["i love you"→5, "island"→3, "iroman"→2, "i love leetcode"→2]
//
// input('i'):
//   currentInput = "i"
//   Move pointer to "i" node
//   "i" node's register = {i love you:5, island:3, iroman:2, i love leetcode:2}
//   After sorting:
//     (-5, "i love you")        → 1st
//     (-3, "island")            → 2nd
//     (-2, "i love leetcode")   → 3rd  (space ASCII=32 < 'r' ASCII=114)
//     (-2, "iroman")            → 4th  (cut off)
//   RETURN: ["i love you", "island", "i love leetcode"] ✓
//
// input(' '):
//   currentInput = "i "
//   Move pointer to "i " node
//   "i " node's register = {i love you:5, i love leetcode:2}
//   RETURN: ["i love you", "i love leetcode"] ✓
//
// input('a'):
//   currentInput = "i a"
//   "i " node has NO child 'a' → dead end
//   currentNode = null
//   RETURN: [] ✓
//
// input('#'):
//   Insert "i a" into trie with freq=1
//   Reset currentInput = ""
//   Reset currentNode = root
//   RETURN: [] ✓
// =========================================================