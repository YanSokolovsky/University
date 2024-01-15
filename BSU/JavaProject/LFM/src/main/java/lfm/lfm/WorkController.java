package lfm.lfm;

import com.almasb.fxgl.entity.action.Action;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import lfm.lfm.calc.CalcWithLib;

import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.util.ArrayList;
import java.util.Objects;


public class WorkController {

    private String options;
    @FXML
    protected void ButtonReadClicked(ActionEvent event) throws MalformedURLException {
        cfile.setText("choose file");
        File file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\folder.png");//TODO поменять место положение фалов
        String localUrl = file.toURI().toURL().toString();
        Image im = new Image(localUrl);
        image2.setImage(im);
        image1.setVisible(false);
        image.setVisible(false);
        b1.setVisible(false);
        b2.setVisible(false);
        options = "read";
    }
    @FXML
    protected void ButtonWriteClicked(ActionEvent event) throws MalformedURLException {
        cfile.setText("choose file");
        File file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\folder.png");//TODO поменять место положение фалов
        String localUrl = file.toURI().toURL().toString();
        Image im = new Image(localUrl);
        image2.setImage(im);
        image1.setVisible(false);
        image.setVisible(false);
        b1.setVisible(false);
        b2.setVisible(false);
        options = "write";
    }
    @FXML
    protected void ButtonEncodeClicked(ActionEvent event) throws MalformedURLException {
        cfile.setText("choose file");
        File file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\folder.png");//TODO поменять место положение фалов
        String localUrl = file.toURI().toURL().toString();
        Image im = new Image(localUrl);
        image2.setImage(im);
        image1.setVisible(false);
        image.setVisible(false);
        b1.setVisible(false);
        b2.setVisible(false);
        options = "encode";
    }
    @FXML
    protected void ButtonDecodeClicked(ActionEvent event) throws MalformedURLException {
        cfile.setText("choose file");
        File file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\folder.png");//TODO поменять место положение фалов
        String localUrl = file.toURI().toURL().toString();
        Image im = new Image(localUrl);
        image2.setImage(im);
        image1.setVisible(false);
        image.setVisible(false);
        b1.setVisible(false);
        b2.setVisible(false);
        options = "decode";
    }
    @FXML
    protected void ButtonArchiveClicked(ActionEvent event) throws MalformedURLException {
        cfile.setText("choose file");
        File file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\folder.png");//TODO поменять место положение фалов
        String localUrl = file.toURI().toURL().toString();
        Image im = new Image(localUrl);
        image2.setImage(im);
        file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\arch.png");//TODO поменять место положение фалов
        localUrl = file.toURI().toURL().toString();
        im = new Image(localUrl);
        image1.setImage(im);
        image1.setVisible(true);
        image.setVisible(true);
        b1.setVisible(true);
        b2.setVisible(true);
        options = "arch";
    }
    @FXML
    protected void ButtonDearchiveClicked(ActionEvent event) throws MalformedURLException {
        cfile.setText("choose archive");
        File file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\arch.png");//TODO поменять место положение фалов
        String localUrl = file.toURI().toURL().toString();
        Image im = new Image(localUrl);
        image2.setImage(im);
        file = new File("C:\\Users\\wexes\\source\\repos\\BSU\\JavaProject\\folder.png");//TODO поменять место положение фалов
        localUrl = file.toURI().toURL().toString();
        im = new Image(localUrl);
        image1.setImage(im);
        image1.setVisible(true);
        image.setVisible(true);
        b1.setVisible(false);
        b2.setVisible(false);
        options = "dearch";
    }
    @FXML
    protected  void Calculate(ActionEvent event) {
        CalcWithLib calc = new CalcWithLib();
        for (int i = 0; i < com.expressions.size(); i++) {
            com.expressions.set(i, String.valueOf(calc.Calculate(com.expressions.get(i))));
        }
    }
    @FXML
    protected void ClearBuffer(ActionEvent event) {
        com.expressions = new ArrayList<>();
        area.setText(" ");
    }

    private Stage stage;
    private Scene scene;
    private Parent parent;
    @FXML
    private Label cfile;
    @FXML
    private RadioButton b1;
    @FXML
    private RadioButton b2;
    @FXML
    private ImageView image2;
    @FXML
    private ToggleGroup r;
    @FXML
    private ImageView image1;
    private final Commands com = new Commands();
    @FXML
    private TextArea area;
    @FXML
    private ImageView image;
    @FXML
    protected void CheckBuffer(ActionEvent event) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < com.expressions.size(); i++) {
            res.append(com.expressions.get(i));
            res.append('\n');
        }
        area.setText(res.toString());
    }

    public void ButtonChooseFile(MouseEvent mouseEvent) {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Choosing file");
        File file = fileChooser.showOpenDialog(((Node)mouseEvent.getSource()).getScene().getWindow());
        if (file == null) {
            return;
        }
        String name = file.getPath();
        switch (options) {
            case "read" -> {
                com.read(name);
            }
            case "write" -> {
                com.write(name);
            }
            case "encode" -> {
                com.encode(name);
            }
            case "decode" -> {
                com.decode(name);
            }
            case "arch" -> {
                RadioButton selectedRadioButton = (RadioButton)r.getSelectedToggle();
                String toggleGroupValue = selectedRadioButton.getText();
                com.archive(name, toggleGroupValue);
            }
            case "dearch" -> {
                com.dearchive(name);
            }
        }
    }
}