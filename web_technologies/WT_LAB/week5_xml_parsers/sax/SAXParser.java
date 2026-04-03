import java.io.File;
import java.util.Scanner;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class SAXParser {

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter user-id of the Student: ");
            String uid = sc.next();

            File inputFile = new File("INPUT.xml");   // Ensure file name matches
            SAXParserFactory factory = SAXParserFactory.newInstance();
            SAXParser saxParser = factory.newSAXParser();

            UserHandler userHandler = new UserHandler(uid);
            saxParser.parse(inputFile, userHandler);

            if (!userHandler.isFound()) {
                System.out.println("The given user-id " + uid + " is not present in XML Document");
            }
            sc.close();
        }
        
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class UserHandler extends DefaultHandler {

    private String uid;
    private boolean bUserId = false;
    private boolean bName = false;
    private boolean bGender = false;
    private boolean bMarks = false;
    private boolean found = false;

    private String currentUserId;

    public UserHandler(String uid) {
        this.uid = uid;
    }

    public boolean isFound() {
        return found;
    }

    @Override
    public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
        if (qName.equalsIgnoreCase("userid")) {
            bUserId = true;
        } else if (qName.equalsIgnoreCase("name")) {
            bName = true;
        } else if (qName.equalsIgnoreCase("gender")) {
            bGender = true;
        } else if (qName.equalsIgnoreCase("marks")) {
            bMarks = true;
        }
    }

    @Override
    public void characters(char[] ch, int start, int length) throws SAXException {
        String value = new String(ch, start, length);

        if (bUserId) {
            currentUserId = value;
            bUserId = false;
        } else if (bName && uid.equals(currentUserId)) {
            System.out.println("Student Name   : " + value);
            bName = false;
        } else if (bGender && uid.equals(currentUserId)) {
            System.out.println("Student Gender : " + value);
            bGender = false;
        } else if (bMarks && uid.equals(currentUserId)) {
            System.out.println("Marks          : " + value);
            bMarks = false;
            found = true; // Mark as found once we print marks
        }
    }
}
