import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.chrome.ChromeOptions;
import org.openqa.selenium.WebElement;

import java.util.ArrayList;

public class Test {
  private static WebDriver MakeChromeDriver() {
    System.setProperty("webdriver.chrome.driver", "drivers/chromedriver");
    ChromeOptions options = new ChromeOptions();
    options.addArguments("-incognito");
    ChromeDriver driver = new ChromeDriver(options);
    driver.get("http://www.google.com");
    return driver;
  }

  public static void main(String[] args) {
    ArrayList<Thread> runners = new ArrayList<Thread>();

    try {    
      for (int i=0; i<20; ++i) {
        runners.add(new Thread(new TestRunner(MakeChromeDriver())));
      }

      Thread.sleep(5000);

      for (Thread runner : runners) { runner.start(); }
      for (Thread runner : runners) { runner.join(); }
    } catch (Exception e) {
      System.out.println(e.toString());
    }
  }
}
