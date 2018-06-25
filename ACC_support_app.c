using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace sprashwindow1
{
    public partial class Form1 : Form
    {

        double R;//抵抗R
        double L;//インダクタンスL
        double C;//コンダクタンスC
        double Z;//インピーダンスZ
        double F;//周波数F
        double E;//電圧値E
        double W;//各周波数ω
        double degZ;//インピーダンスZの位相
        float real;//インピーダンスZの実部
        float imaginary;//インピーダンスZの虚部
        double a;





        public Form1()
        {
            InitializeComponent();
        }


        //Rの場合
        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            textBox1.Text = trackBar2.Value.ToString();  // 位置を取得
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;
            degZ = Math.Atan((W * L - (1 / W * C)) / R);
            real = (float)((E*R) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            imaginary = (float)((-E * (W * L - 1 / (W * C))) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));

            //描画先とするImageオブジェクトを作成する
            Bitmap canvas = new Bitmap(pictureBox3.Width, pictureBox3.Height); //cavasがビットマップ形式で書く紙（幅がピクチャボックスのもの）
            //ImageオブジェクトのGraphicsオブジェクトを作成する
            pictureBox3.Image = canvas;//ピクチャボックスにかけるようにする。紙をピクチャボックスに張る
            Graphics g = Graphics.FromImage(pictureBox3.Image);//ピクチャボックスに書くという宣言

            g.Clear(Color.White);//白色で初期化
            Pen blackPen = new Pen(Color.Black, 1);
            Pen redPen = new Pen(Color.Red, 1);
            Pen border = new Pen(Color.Black, 1);
            blackPen.EndCap = LineCap.ArrowAnchor;//終点に矢印をつける
            redPen.EndCap = LineCap.ArrowAnchor;
            g.DrawLine(redPen, 180, 85, 180 + 10 * real, 85 + 10 * imaginary);
            g.DrawLine(blackPen, 180, 85, 180 + (float)E, 85);
            g.DrawLine(border, 180, 0, 180, 300);
            g.DrawLine(border, 0, 85, 500, 85);
            testChart();
        }


        //Ｌの場合
        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            // TrackBar のスライダの位置を表示する
            textBox3.Text = trackBar3.Value.ToString();  // 位置を取得
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;
            degZ = Math.Atan((W * L - (1 / W * C)) / R);
            real = (float)((E*R) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            imaginary = (float)((-E * (W * L - 1 / (W * C))) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));



            //描画先とするImageオブジェクトを作成する
            Bitmap canvas = new Bitmap(pictureBox3.Width, pictureBox3.Height); //cavasがビットマップ形式で書く紙（幅がピクチャボックスのもの）
            //ImageオブジェクトのGraphicsオブジェクトを作成する
            pictureBox3.Image = canvas;//ピクチャボックスにかけるようにする。紙をピクチャボックスに張る
            Graphics g = Graphics.FromImage(pictureBox3.Image);//ピクチャボックスに書くという宣言

            g.Clear(Color.White);//白色で初期化

            //Penオブジェクトの作成(幅10の黒色)
            Pen blackPen = new Pen(Color.Black, 1);
            Pen redPen = new Pen(Color.Red, 1);

            //終点に矢印をつける
            blackPen.EndCap = LineCap.ArrowAnchor;
            redPen.EndCap = LineCap.ArrowAnchor;
            //線を描画
            g.DrawLine(redPen, 180, 85, 180 + 10 * real, 85 + 10 * imaginary);
            g.DrawLine(blackPen, 180, 85, 180 + (float)E, 85);

            Pen border = new Pen(Color.Black, 1);
            //線を描画
            g.DrawLine(border, 180, 0, 180, 300);
            //線を描画
            g.DrawLine(border, 0, 85, 500, 85);
            testChart();
        }



        //Ｃの場合
        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            // TrackBar のスライダの位置を表示する

            textBox4.Text = trackBar4.Value.ToString();
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;

            degZ = Math.Atan((W * L - (1 / W * C)) / R);
            real = (float)((E*R) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            imaginary = (float)((-E * (W * L - 1 / (W * C))) / (R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C))));
            //real = (float)R;
            //imaginary = (float)(W * L - 1 / (W * C));



            //描画先とするImageオブジェクトを作成する
            Bitmap canvas = new Bitmap(pictureBox3.Width, pictureBox3.Height); //cavasがビットマップ形式で書く紙（幅がピクチャボックスのもの）
            //ImageオブジェクトのGraphicsオブジェクトを作成する
            pictureBox3.Image = canvas;//ピクチャボックスにかけるようにする。紙をピクチャボックスに張る
            Graphics g = Graphics.FromImage(pictureBox3.Image);//ピクチャボックスに書くという宣言

            g.Clear(Color.White);//白色で初期化

            //Penオブジェクトの作成(幅10の黒色)
            Pen blackPen = new Pen(Color.Black, 1);
            Pen redPen = new Pen(Color.Red, 1);

            //終点に矢印をつける
            blackPen.EndCap = LineCap.ArrowAnchor;
            redPen.EndCap = LineCap.ArrowAnchor;
            //線を描画
            g.DrawLine(redPen, 180, 85, 180 + 10*real, 85 + 10*imaginary);
            g.DrawLine(blackPen, 180, 85, 180 + (float)E, 85);

            Pen border = new Pen(Color.Black, 1);
            //線を描画
            g.DrawLine(border, 180, 0, 180, 300);
            //線を描画
            g.DrawLine(border, 0, 85, 500, 85);
            testChart();

        }

        public void testChart()   //これで関数を作った。上のように宣言してやればその戻り値なし関数を発動できる。
        {
            R = (double)trackBar2.Value;
            L = (double)trackBar3.Value / (-1000);
            C = (double)trackBar4.Value / (-1000000);
            Z = Math.Sqrt(R * R + (W * L - 1 / (W * C)) * (W * L - 1 / (W * C)));
            F = Convert.ToDouble(textBox2.Text);
            E = Convert.ToDouble(textBox5.Text);
            W = 2 * Math.PI * F;
            degZ = Math.Atan((W * L - 1 / (W * C)) / R);

            // 1.Seriesの追加
            chart1.Series.Clear();
            chart1.Series.Add("I");
            chart1.Series.Add("E");

            // 2.グラフのタイプの設定
            chart1.Series["I"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            chart1.Series["E"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;

            // 3.座標の入力
            for (double theta = 0; theta <= 2 * Math.PI; theta += Math.PI / 360)　　　　　
            {
                chart1.Series["I"].Points.AddXY(theta, Math.Sqrt(2)*(E / Z) * Math.Sin(theta + degZ));//E/Zの絶対値をsinに掛けたら大きさも変わる
                chart1.Series["E"].Points.AddXY(theta, Math.Sqrt(2) * E/10 * Math.Sin(theta));
            }

        }

        private void ｒＣ直列回路ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form3 newForm = new Form3();
            newForm.ShowDialog();
        }

        private void ｒＬ直列回路ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form4 newForm = new Form4();
            newForm.ShowDialog();
        }

        private void ｒＬＣ直列回路ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 newForm = new Form1();
            newForm.ShowDialog();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
