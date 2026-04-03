import java.io.File;
import java.util.Scanner;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.w3c.dom.Node;
import org.w3c.dom.Element;

public class DOMParser{

   public static void main(String[] args) {

      try {
  Scanner sc = new Scanner(System.in);
         File inputFile = new File("INPUT.xml");
         DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
         DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
         Document doc = dBuilder.parse(inputFile);
         doc.getDocumentElement().normalize();
 
  System.out.println("Enter user-id of the Student");
         String uid = sc.next();

  System.out.println("Root element :" + doc.getDocumentElement().getNodeName());
         NodeList nList = doc.getElementsByTagName("student");
         System.out.println("----------------------------");

 int c=0;

         for (int temp = 0; temp < nList.getLength(); temp++) {
            Node nNode = nList.item(temp);

            if (nNode.getNodeType() == Node.ELEMENT_NODE) {
               Element eElement = (Element) nNode;
        if (eElement.getElementsByTagName("userid").item(0).getTextContent().equals(uid)){
           System.out.println("Student roll no : " + eElement.getElementsByTagName("userid").item(0).getTextContent());
                  System.out.println("Student Name : " + eElement.getElementsByTagName("name").item(0).getTextContent());
                  System.out.println("Student Gender : " + eElement.getElementsByTagName("gender").item(0).getTextContent());
                  System.out.println("Marks : " + eElement.getElementsByTagName("marks").item(0).getTextContent());
  c = 1;
               }
       }
       sc.close();
         }
 if(c==0) System.out.println("The given user-id "+uid+" is not present in XML Document");
  
      } catch (Exception e) {
         e.printStackTrace();
      }
   }
}
