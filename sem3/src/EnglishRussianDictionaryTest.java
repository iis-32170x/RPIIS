import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

public class EnglishRussianDictionaryTest {
    private EnglishRussianDictionary dictionary;

    @Before
    public void setUp() {
        dictionary = new EnglishRussianDictionary();
    }

    @Test
    public void testAddAndGetTranslation() {
        dictionary.add("hello", "привет");
        assertEquals("привет", dictionary.getTranslation("hello"));

        dictionary.add("world", "мир");
        assertEquals("мир", dictionary.getTranslation("world"));
    }

    @Test
    public void testUpdateTranslation() {
        dictionary.add("hello", "привет");
        dictionary.setTranslation("hello", "здравствуй");
        assertEquals("здравствуй", dictionary.getTranslation("hello"));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testUpdateTranslationWithNullKey() {
        dictionary.setTranslation(null, "новый перевод"); // Обновление с null ключом должно выбросить исключение
    }

    @Test
    public void testRemoveWord() {
        dictionary.add("hello", "привет");
        dictionary.remove("hello");
        assertNull(dictionary.getTranslation("hello"));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testRemoveNullKey() {
        dictionary.remove(null); // Удаление с null ключом должно выбросить исключение
    }

    @Test
    public void testSize() {
        assertEquals(0, dictionary.size());
        dictionary.add("hello", "привет");
        dictionary.add("world", "мир");
        assertEquals(2, dictionary.size());
        dictionary.remove("hello");
        assertEquals(1, dictionary.size());
    }
}