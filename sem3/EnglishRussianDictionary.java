public class EnglishRussianDictionary {
    private DictionaryNode root;
    private int size;

    public EnglishRussianDictionary() {
        this.root = null;
        this.size = 0;
    }

    public int size() {
        return size;
    }
    public void add(String englishWord, String russianTranslation) {
        root = addRecursive(root, englishWord, russianTranslation);
    }

    private DictionaryNode addRecursive(DictionaryNode node, String englishWord, String russianTranslation) {
        if (node == null) {
            size++;
            return new DictionaryNode(englishWord, russianTranslation);
        }
        if (englishWord.compareTo(node.getEnglishWord()) < 0) {
            node.setLeft(addRecursive(node.getLeft(), englishWord, russianTranslation));
        } else if (englishWord.compareTo(node.getEnglishWord()) > 0) {
            node.setRight(addRecursive(node.getRight(), englishWord, russianTranslation));
        } else {
            node.setRussianWord(russianTranslation); // Update translation if exists
        }
        return node;
    }

    public void remove(String englishWord) {
        root = removeRecursive(root, englishWord);
    }

    private DictionaryNode removeRecursive(DictionaryNode node, String englishWord) {
        if (node == null) return null;

        if (englishWord.compareTo(node.getEnglishWord()) < 0) {
            node.setLeft(removeRecursive(node.getLeft(), englishWord));
        } else if (englishWord.compareTo(node.getEnglishWord()) > 0) {
            node.setRight(removeRecursive(node.getRight(), englishWord));
        } else {
            size--;
            if (node.getLeft() == null) return node.getRight();
            if (node.getRight() == null) return node.getLeft();
            node.setEnglishWord(findMin(node.getRight()).getEnglishWord());
            node.setRussianWord(findMin(node.getRight()).getRussianWord());
            node.setRight(removeRecursive(node.getRight(), node.getEnglishWord()));
        }
        return node;
    }

    private DictionaryNode findMin(DictionaryNode node) {
        return node.getLeft() == null ? node : findMin(node.getLeft());
    }

    public String getTranslation(String englishWord) {
        return getTranslationRecursive(root, englishWord);
    }

    private String getTranslationRecursive(DictionaryNode node, String englishWord) {
        if (node == null) return null;
        if (englishWord.equals(node.getEnglishWord())) {
            return node.getRussianWord();
        }
        return englishWord.compareTo(node.getEnglishWord()) < 0
                ? getTranslationRecursive(node.getLeft(), englishWord)
                : getTranslationRecursive(node.getRight(), englishWord);
    }

    public void setTranslation(String englishWord, String newTranslation) {
        DictionaryNode node = findNode(root, englishWord);
        if (node != null) {
            node.setRussianWord(newTranslation);
        } else {
            throw new IllegalArgumentException("Word not found in dictionary.");
        }
    }

    private DictionaryNode findNode(DictionaryNode node, String englishWord) {
        if (node == null) return null;
        if (englishWord.equals(node.getEnglishWord())) {
            return node;
        }
        return englishWord.compareTo(node.getEnglishWord()) < 0 ? findNode(node.getLeft(), englishWord) : findNode(node.getRight(), englishWord);
    }



}


