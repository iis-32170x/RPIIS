class DictionaryNode {
      private String englishWord;
      private String russianTranslation;
      private DictionaryNode left, right;

      public String getEnglishWord() {
          return englishWord;
      }
      public void setEnglishWord(String newEngWord) {
          englishWord = newEngWord;
      }
    public String getRussianWord() {
        return englishWord;
    }
    public void setRussianWord(String newEngWord) {
        englishWord = newEngWord;
    }
    public DictionaryNode getLeft() {
          return left;
    }
    public DictionaryNode getRight() {
        return right;
    }
    public void setLeft(DictionaryNode left) {
          this.left = left;
    }
    public void setRight(DictionaryNode right) {
        this.right = right;
    }


    public DictionaryNode(String englishWord, String russianTranslation) {
        this.englishWord = englishWord;
        this.russianTranslation = russianTranslation;
        this.left = null;
        this.right = null;
    }
}
