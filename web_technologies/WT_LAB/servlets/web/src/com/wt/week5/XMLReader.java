package com.wt.week5;

import javax.xml.parsers.*;
import org.w3c.dom.*;
import java.io.*;

public class XMLReader {
    public static void main(String[] args) throws Exception {
        File inputFile = new File("students.xml");
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = dBuilder.parse(inputFile);
        doc.getDocumentElement().normalize();

        NodeList nList = doc.getElementsByTagName("student");
        for (int i = 0; i < nList.getLength(); i++) {
            Element e = (Element) nList.item(i);
            System.out.println("Name: " + e.getElementsByTagName("name").item(0).getTextContent());
        }
    }
}
